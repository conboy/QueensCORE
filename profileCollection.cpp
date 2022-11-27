

#include "profileCollection.h"
#include <iostream>

using namespace std;

//creates new profile database
int profile_collection::create_profileDB(const char *dbName) {
    sqlite* DB;
    int exit = 0;

    exit = sqlite3_open("profileDB", &DB);

    if(exit) throw DbProfileFail();

    sqlite3_close(DB);

    return exit;
}

//creates an empty table for holding profiles
int profile_collection::createProfileTable() {
    sqlite3* DB;

    string sql = "CREATE TABLE IF NOT EXISTS PROFILES("
                 "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                 "USER      TEXT NOT NULL, "
                 "PASSWORD      TEXT NOT NULL, "
                 "EMAIL         TEXT NOT NULL,):";

    try{
        int exit = 0;
        exit = sqlite3_open("profileDB", &DB);
        char* messageError;

        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
    }

    if (exit != SQLITE_OK){
        throw DbProfileFail();
        sqlite3_free(messageError);
    }
    else{
        sqlite3_close(DB);
    }

    catch (const exception & e){
        cerr << e.what();
    }

    return 0;
}

//add a created profiles details to the database
int profile_collection::storeToProfileDB(profile prof) {

    sqlite3* DB;
    char* messageError;

    int exit = sqlite3_open("profileDB", &DB;);

    //use getters to get fields to add to new entry n DB
    string username = prof.get_username();
    string password = prof.get_password();
    string email = prof.get_email();

    string seperator ("','");
    string end ("');");

    string sql("INSERT INTO POSTS (USER, PASSWORD, EMAIL) VALUES ('"); //add info to new table entry
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
        throw DbPostFail();
    }
    else {
        cout << "Added profile into sql" << endl;
    }

    return 0;
}


