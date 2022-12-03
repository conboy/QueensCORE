

#include "profile_collection.h"
#include "profile_class.h"

#include <iostream>

using namespace std;

string dup;
bool duplicate;

char* DbProfileFail::what(){
    return (char *) "Database creation or access failed.";
}
profile_collection::profile_collection(const char *directory): s(directory) {};
//creates new profile database
int profile_collection::create_profileDB() {
    sqlite3* DB;
    int exit = 0;

    exit = sqlite3_open(s, &DB);

    if(exit) throw DbProfileFail();
    else cout << "Successfully created database" << endl;

    sqlite3_close(DB);

    return exit;
}

//creates an empty table for holding profiles
int profile_collection::createProfileTable() {

    sqlite3* DB;

    string sql = "CREATE TABLE IF NOT EXISTS PROFILES("
                 "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                 "USER          TEXT NOT NULL, "
                 "PASSWORD      TEXT NOT NULL, "
                 "EMAIL         TEXT NOT NULL);";

    try {
        int exit = 0;
        exit = sqlite3_open(s, &DB);
        char *messageError;

        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

        if (exit != SQLITE_OK) {
            sqlite3_free(messageError);
            throw DbProfileFail();
        } else {
            sqlite3_close(DB);
            cout << "Created DB Table successfully" << endl;
        }
    }

    catch (const exception & e){
        cerr << "DB table creation failed" << endl;
    }
    return 0;
}

//add a created profiles details to the database
int profile_collection::storeToProfileDB(profile_class prof) {

    sqlite3* DB;
    char* messageError;

    int exit = sqlite3_open(s, &DB);

    //use getters to get fields to add to new entry n DB
    string username = prof.get_username();
    string password = prof.get_password();
    string email = prof.get_email();

    string seperator ("','");
    string end ("');");

    string sql("INSERT INTO PROFILES (USER, PASSWORD, EMAIL) VALUES ('"); //add info to new table entry
    //convert variables holding data to string that is read by SQLite
    sql.append(username);
    sql.append(seperator);
    sql.append(password);
    sql.append(seperator);
    sql.append(email);
    sql.append(end);

    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
    if (exit != SQLITE_OK){
        sqlite3_free(messageError);
        throw DbProfileFail();
    }
    else {
        cout << "Added profile into sql" << endl;
    }

    return 0;
}

int callbackprofile(void* notUsed, int argc, char** argv, char** azColName) {
    if (argc <= 0) cout << "Empty DB" << endl;
    else {
        if (dup == argv[1])
            duplicate = true;
        else duplicate = false;
    }
}



bool profile_collection::checkForProfile(const string username) {
    dup = username;
    sqlite3* DB;
    char* errorMessage;
    string sql = "SELECT * FROM PROFILES WHERE USER = '";
    sql.append(username);
    sql.append("';");

    int exit = sqlite3_open(s, &DB);


    exit = sqlite3_exec(DB, sql.c_str(), callbackprofile, NULL, &errorMessage);

    if (exit != SQLITE_OK) {
        cerr << "Error in selecting data" << endl;
        sqlite3_free(errorMessage);
        throw DbProfileFail();
    }

    return duplicate;
}

