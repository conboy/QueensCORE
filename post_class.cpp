#include "post_class.h"
#include <vector>
#include <exception>
//Change #1
using namespace std;

char* MissingTitle::what() {
    return (char *) "Please input a title";
}
char* MissingDescription::what() {
    return (char *) "Please input a description";
}


Post::Post(string own, string t, string d, int type){
    if (t == "\0" || t== "\n" || t.size() == 1) throw MissingTitle();
    if (d == "\0" || d == "\n" || d.size() == 1) throw MissingDescription();
    owner = own;
    title = t;
    description = d;
    event = (eventType)type;
    num_comments = 0;
    down = 0;
    up = 0;
    allComments = "";
}

//Getters
string Post::get_owner() { return owner; }
string Post::get_description() { return description; }
string Post::get_title() { return title; }
int Post::get_num_com() { return num_comments;}
int Post::get_upvote() {return up;}
int Post::get_downvote() {return down;}
vector<string> Post::get_comment(){ return com;}
vector<string> Post::get_comment_owner() {return com_owner;}
string Post::get_event_type(){
    switch(event){
        case 0:
            return ("Nightlife");
            break;
        case 1:
            return ("Special Event");
            break;
        case 2:
            return ("House Party");
            break;
        case 3:
            return("Campus Event");
            break;
        default:
            return ("Error");
    }
}
string Post::returnAllComments() {return allComments;}

void Post::comment(string own, string c) {
    com.push_back(c);
    com_owner.push_back(own);
    num_comments++;
    allComments.append(own);
    allComments.append(": ");
    allComments.append(c);
    allComments.append("$ ");
}

void Post::setAllComments(string comments){
    allComments = comments;
}

string Post::postToString(Post post) {
    string postString="";
    postString += to_string(post.get_upvote()) + ":"
            + to_string(post.get_downvote()) + ":"
            + post.get_title() + ":"
            + post.get_owner() + ":"
            + post.get_description() //+ ":"
            //+ post.get_comment_string()
            + ";";
    return postString;
}

void Post::upvote(int upvote) {up = upvote;}
void Post::downvote(int downvote){down = downvote;}

void Post::upvote(void) {up++;}
void Post::downvote(void){down++;}





