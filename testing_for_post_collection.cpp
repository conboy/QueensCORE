//
// Created by liams on 2022-11-26.
//

#include "post_collection.h"
#include <string>
#include <iostream>

int main (){
    Post test1 ("Liam", "Test1", "Testing if the post collection db works", 0);
    Post test2 ("Liam", "Test2", "Testing if the post collection db works", 0);
    Post test3 ("Claire", "Test3", "Testing if the post collection db works", 0);
    Post test4 ("Jonathon", "Test4", "Testing if the post collection db works", 1);
    test1.comment("David", "is a lil bitch.");
    test1.comment("Liam", " Is not a lil bitch.");


    vector<Post> data;
    data.push_back(test1);
    data.push_back(test2);
    data.push_back(test3);
    data.push_back(test4);

    try {
        const char* dir = "C:\\Users\\liams\\CLionProjects\\team-17-indian\\Post.db";
        PostCollection db(dir);

        //Testing creeation
        db.createPostDB();
        db.createPostTable();
        cout << endl;

        //Storing the vector of Posts to the database
        cout << "Storing these bitches";
        db.storeVectorPosts(data);


        //Updating the votes in database
        db.updateVotes("Test1", 5, 6);

        //Selecting all data with owner liam
        db.selectPostDataOwner("Liam");
        data = getSelectedData(); //Gettng all data wiht owner liam


        //Prints out all with owner Liam
        for (Post temp : data){
            cout << "Owner: " << temp.get_owner() << "\nTitle: " << temp.get_title() <<  endl;
            cout << "Description: " << temp.get_description() << endl;
            cout << "Upvotes: " << temp.get_upvote() << " | Downvotes: " << temp.get_downvote() << endl;
            cout << "Event Type: " << temp.get_event_type() << endl;
            cout << "All comment string: " << temp.returnAllComments() << endl;
            cout << endl;
        }


        cout << "================================================================" << endl;
        //Selecting all nightlife posts
        db.selectPostDataEvent(0);
        data = getSelectedData();  //Placing nightlife posts in vector

        //Print all nightlife events
        for (Post temp : data){
            cout << "Owner: " << temp.get_owner() << "\nTitle: " << temp.get_title() <<  endl;
            cout << "Description: " << temp.get_description() << endl;
            cout << "Upvotes: " << temp.get_upvote() << " | Downvotes: " << temp.get_downvote() << endl;
            cout << "Event Type: " << temp.get_event_type() << endl;
            cout << "All comment string: " << temp.returnAllComments() << endl;
            cout << endl;
        }

        //delete all the post data in db
        db.deleteData(0);
        db.deleteData(1);


    } catch (DbPostFail &e){
        cerr << "Error: " << e.what() << endl;
    }


    return 0;
}