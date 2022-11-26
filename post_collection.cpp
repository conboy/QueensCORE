//
// Created by liams on 2022-11-25.
//

#include "post_collection.h"


char* DbPostFail::what(){
    return (char *) "Database creation or access failed.";
}

int PostCollection::createPostDB(const char* s){

    sqlite3* DB;
    int exit = 0;

    exit = sqlite3_open(s, &DB);

    if (exit) throw DbPostFail();
    else cout << "Successfully created database" << endl;

    sqlite3_close(DB);

    return exit;
}

int PostCollection::createPostTable(const char* s) {

    sqlite3* DB;

    string sql = "CREATE TABLE IF NOT EXISTS POSTS("
                 "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                 "OWNER       TEXT NOT NULL, "
                 "TITLE       TEXT NOT NULL, "
                 "DESCRIPTION TEXT NOT NULL, "
                 "EVENTTYPE   TEXT NOT NULL,"
                 "UPVOTE      INT NOT NULL,"
                 "DOWNVOTE    INT NOT NULL);";
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
    return 0;
}

int PostCollection::storeToPostDB(const char* s, Post post) {
    sqlite3* DB;
    char* messageError;

    int exit = sqlite3_open(s, &DB);

    string owner = post.get_owner();
    string title = post.get_title();
    string description = post.get_description();
    string event = post.get_event_type();

    int upvote = post.get_upvote();
    int downvote = post.get_downvote();

    string seperator ("','");
    string end ("');");

    string sql("INSERT INTO POSTS (OWNER, TITLE, DESCRIPTION, EVENTTYPE, UPVOTE, DOWNVOTE) VALUES ('");
    sql.append(owner);
    sql.append(seperator);
    sql.append(title);
    sql.append(seperator);
    sql.append(description);
    sql.append(seperator);
    sql.append(event);
    sql.append(seperator);
    sql.append(to_string(upvote));
    sql.append(seperator);
    sql.append(to_string(downvote));
    sql.append(end);

    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
    if (exit != SQLITE_OK){
        sqlite3_free(messageError);
        throw DbPostFail();
    }
    else {
        cout << "Added post into sql" << endl;
    }

    return 0;
}

static int callback(void* notUsed, int argc, char** argv, char** azColName){
    for (int i = 0; i < argc; i++){
        cout << azColName[i] << ": " << argv[i] << endl;
    }
    cout << endl;
    return 0;
}

int PostCollection::selectPostData(const char *s) {
    sqlite3* DB;
    char* errorMessage;
    string sql = "SELECT * FROM POSTS;";

    int exit = sqlite3_open(s, &DB);

    exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &errorMessage);

    if (exit != SQLITE_OK) {
        cerr << "Error in selecting data" << endl;
        sqlite3_free(errorMessage);
        throw DbPostFail();
    } else {
        cout << "Successfully selected data" << endl;
    }
    return 0;
}

int PostCollection::deleteData(const char *s, string column, string del) {
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
    } else {
        cout << "Successfully deleted " << del << " from database" << endl;
    }
    return 0;
}
