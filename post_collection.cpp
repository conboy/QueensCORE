//
// Created by liams on 2022-11-25.
//

#include "post_collection.h"


char* DbPostFail::what(){
    return (char *) "Database creation or access failed.";
}

vector<Post> selectedData;

PostCollection::PostCollection(const char* dir): s(dir){}

int PostCollection::createPostDB(){

    sqlite3* DB;
    int exit = 0;

    exit = sqlite3_open(s, &DB);

    if (exit) throw DbPostFail();
    else cout << "Successfully created database" << endl;

    sqlite3_close(DB);

    return exit;
}

int PostCollection::createPostTable() {

    sqlite3* DB;

    string sql = "CREATE TABLE IF NOT EXISTS POSTS("
                 "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                 "OWNER       TEXT NOT NULL, "
                 "TITLE       TEXT NOT NULL, "
                 "DESCRIPTION TEXT NOT NULL, "
                 "EVENTTYPE   INT NOT NULL,"
                 "UPVOTE      INT NOT NULL,"
                 "DOWNVOTE    INT NOT NULL,"
                 "COMMENTS    TEXT NOT NULL);";
    try {
        int exit = 0;
        exit = sqlite3_open(s, &DB);
        char *messageError;

        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

        if (exit != SQLITE_OK) {
            sqlite3_free(messageError);
            throw DbPostFail();
        } else {
            sqlite3_close(DB);
            cout << "Created DB Table successfully" << endl;
        }
    }
    catch (const exception & e){
           cerr  << "Database table creation failed" << endl;
    }
//    sql = "CREATE TABLE IF NOT EXISTS COMMENTS("
//                 "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
//                 "TITLE       TEXT NOT NULL"
//                 "COWNER      TEXT NOT NULL"
//                 "COMMENT     TEXT NOT NULL);";
//    try {
//        int exit = 0;
//        exit = sqlite3_open(s, &DB);
//        char *messageError;
//
//        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
//
//        if (exit != SQLITE_OK) {
//            sqlite3_free(messageError);
//            throw DbPostFail();
//        } else {
//            sqlite3_close(DB);
//            cout << "Created Comment Table successfully" << endl;
//        }
//    }
//    catch (const exception & e){
//        cerr  << "Database table creation failed" << endl;
//    }
    return 0;
}

int PostCollection::storeToPostDB(Post post) {
    sqlite3* DB;
    char* messageError;

    int exit = sqlite3_open(s, &DB);

    string owner = post.get_owner();
    string title = post.get_title();
    string description = post.get_description();
    string eString = post.get_event_type();
    int event;
    if (eString == "Nightlife") event = 0;
    if (eString == "Special Event") event = 1;
    if (eString == "House Party") event = 2;
    if (eString == "Campus Event") event = 3;
    int upvote = post.get_upvote();
    int downvote = post.get_downvote();

    string comments = post.returnAllComments();

    string seperator ("','");
    string end ("');");

    string sql("INSERT INTO POSTS (OWNER, TITLE, DESCRIPTION, EVENTTYPE, UPVOTE, DOWNVOTE, COMMENTS) VALUES ('");
    sql.append(owner);
    sql.append(seperator);
    sql.append(title);
    sql.append(seperator);
    sql.append(description);
    sql.append(seperator);
    sql.append(to_string(event));
    sql.append(seperator);
    sql.append(to_string(upvote));
    sql.append(seperator);
    sql.append(to_string(downvote));
    sql.append(seperator);
    sql.append(comments);
    sql.append(end);

    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
    if (exit != SQLITE_OK){
        sqlite3_free(messageError);
        throw DbPostFail();
    }
//   if (post.get_num_com() != 0) {
//       for (int i = 0; i < post.get_num_com(); i++){
//           string sqlc("INSERT INTO COMMNETS (TITLE, COWNER, COMMNET) VALUES ('");
//           sqlc.append(title);
//           sqlc.append(seperator);
//           sqlc.append(cowner[i]);
//           sqlc.append(seperator);
//           sqlc.append(comment[i]);
//           sqlc.append(end);
//
//           exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
//           if (exit != SQLITE_OK) {
//               sqlite3_free(messageError);
//               throw DbPostFail();
//           }
//       }
//   }
    sqlite3_close(DB);
    cout << "Posted successfully to database" << endl;
    return 0;
}

int PostCollection::storeVectorPosts(vector<Post> post){
    for (Post temp : post){
        PostCollection::storeToPostDB(temp);
    }
    return 0;
}

vector<Post> getSelectedData(){
    vector<Post> temp = selectedData;
    selectedData.clear();
    return temp;
}

int callback(void* notUsed, int argc, char** argv, char** azColName){
    if (argc <= 0) cout << "Empty DB" << endl;
    else {
        string eventS = argv[4];
        int event = stoi(eventS);
        Post temp(argv[1],argv[2],argv[3], event);
        string upv = argv[5];
        string downv = argv[6];
        int up = stoi(upv);
        int down = stoi(downv);
        temp.upvote(up);
        temp.downvote(down);
        temp.setAllComments(argv[7]);
        selectedData.push_back(temp);
    }
    return 0;
}

int PostCollection::selectPostDataAll() {
    sqlite3* DB;
    char* errorMessage;
    string sql = "SELECT * FROM POSTS;";

    int exit = sqlite3_open(s, &DB);

    exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &errorMessage);

    if (exit != SQLITE_OK) {
        cerr << "Error in selecting data" << endl;
        sqlite3_free(errorMessage);
        throw DbPostFail();
    }
    return 0;
}

int PostCollection::selectPostDataEvent(int event) {
    sqlite3* DB;
    char* errorMessage;
    string sql = "SELECT * FROM POSTS WHERE EVENTTYPE = '";
    sql.append(to_string(event));
    sql.append("';");

    int exit = sqlite3_open(s, &DB);

    exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &errorMessage);

    if (exit != SQLITE_OK) {
        cerr << "Error in selecting data" << endl;
        sqlite3_free(errorMessage);
        throw DbPostFail();
    }
    return 0;
}

int PostCollection::selectPostDataOwner(string owner) {
    sqlite3* DB;
    char* errorMessage;
    string sql = "SELECT * FROM POSTS WHERE OWNER = '";
    sql.append(owner);
    sql.append("';");

    int exit = sqlite3_open(s, &DB);

    exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &errorMessage);

    if (exit != SQLITE_OK) {
        cerr << "Error in selecting data" << endl;
        sqlite3_free(errorMessage);
        throw DbPostFail();
    }
    return 0;
}

int PostCollection::deleteData(string column, string del) {
    sqlite3* DB;
    char* errorMessage;
    string sql = "DELETE FROM POSTS WHERE ";
    sql.append(column);
    sql.append(" = '");
    sql.append(del);
    sql.append("';");


    int exit = sqlite3_open(s, &DB);

    exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &errorMessage);

    if (exit != SQLITE_OK) {
        cerr << "Error in deleting data" << endl;
        sqlite3_free(errorMessage);
        throw DbPostFail();
    }
    return 0;
}

int PostCollection::deleteData(int event) {
    sqlite3* DB;
    char* errorMessage;
    string sql = "DELETE FROM POSTS WHERE EVENTTYPE = '";
    sql.append(to_string(event));
    sql.append("';");


    int exit = sqlite3_open(s, &DB);

    exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &errorMessage);

    if (exit != SQLITE_OK) {
        cerr << "Error in deleting data" << endl;
        sqlite3_free(errorMessage);
        throw DbPostFail();
    }
    return 0;
}

int PostCollection::updateVotes(string title, int up, int down){
    sqlite3* DB;
    char* errorMessage;
    string sql = "UPDATE POSTS SET UPVOTE = '";
    sql.append(to_string(up));
    sql.append("', DOWNVOTE = '");
    sql.append(to_string(down));
    sql.append("' WHERE TITLE = '");
    sql.append(title);
    sql.append("';");

    int exit = sqlite3_open(s, &DB);

    exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &errorMessage);

    if (exit != SQLITE_OK) {
        cerr << "Error in updating vote data" << endl;
        sqlite3_free(errorMessage);
        throw DbPostFail();
    }
    return 0;
}