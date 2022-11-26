//
// Created by liams on 2022-11-26.
//

#include "post_collection.h"
#include <string>
#include <iostream>

int main (){
    Post test1 ("Liam", "Test Post", "Testing if the post collection db works", 1);
    Post test2 ("Salass", "Test Post 2", "Testing if the post collection db works", 1);

    try {
        PostCollection testdb;
        const char* dir = "C:\\Users\\liams\\CLionProjects\\team-17-indian\\Post.db";
        //Testing creeation
        testdb.createPostDB(dir);
        testdb.createPostTable(dir);
        cout << endl;



        //Testing storing a post to DB
        testdb.storeToPostDB(dir, test1);
        testdb.storeToPostDB(dir, test2);
        cout << endl;

        //Testing delete data
        testdb.deleteData(dir, "OWNER", "Salass");
        cout << endl;

        //Testing Selecting data
        testdb.selectPostData(dir);

        testdb.deleteData(dir, "OWNER", "Liam");
        cout << endl;

        testdb.selectPostData(dir);


    } catch (DbPostFail &e){
        cerr << "Error: " << e.what() << endl;
    }


    return 0;
}