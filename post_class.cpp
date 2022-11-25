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

void Post::comment(string own, string c) {
    com.push_back(c);
    com_owner.push_back(own);
    num_comments++;
}

void Post::upvote() {up++;}
void Post::downvote(){down++;}




