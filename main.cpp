#include <iostream>
#include "post_class.h"
#include <string>
using namespace std;

int main() {
    string owner;
    string description;
    string title;
    cout << "Enter owner:" <<endl;
    cin >> owner; //Note that using cin doesnt work with spaces.
    cout << "Enter Title:" <<endl;
    cin >> title;
    cout << "Enter Description:" <<endl;
    cin >> description;
    Post first(owner, title, description);
    first.upvote();
    first.comment("Salass", "is sexy");


    //Prints all info on post.
    cout << "Owner: " << first.get_owner() << endl;
    cout << "Title: " << first.get_title() << endl;
    cout << "Description: " << first.get_description() << endl;
    cout << "Upvotes: " << to_string(first.get_upvote()) << "| Downvotes: " << to_string(first.get_downvote()) << endl;
    cout << "Number of comments " << to_string(first.get_num_com()) << endl;
    vector<string> comments = first.get_comment();
    vector<string> com_owner = first.get_comment_owner();
    for (int i = 0; i < first.get_num_com(); i++) {
        cout << "Comment #" << to_string(i + 1);
        cout << " | Owner: " << comments[i] << endl;
        cout<< "Comment: " << com_owner[i] << endl;
    }

    return 0;
}

