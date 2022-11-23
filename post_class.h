
#include <string>
#include <vector>

using namespace std;

//Exception in case that no title is given as input
class MissingTitle : public std::exception {
public:
    char *what();
};

//Exception for if no description is given as input
class MissingDescription : public std::exception {
public:
    char *what();
};


class Post {
private:
    string owner;
    string title;
    string description;

    //Value to store time since creation of post
    //const unsigned long creation_time;


    //Vector storing comments and
    vector<string> com;
    vector<string> com_owner;
    int num_comments;


    //Ints to hold upvoting and downvoting
    unsigned int up;
    unsigned int down;


public:
    //Constructor (owner, title, description)
    Post(string owner, string title, string description);

    //Getters
    string get_owner();
    string get_title();
    string get_description();
    //unsigned long get_time();
    int get_upvote();
    int get_downvote();
    int get_num_com();
    vector<string> get_comment();
    vector<string> get_comment_owner();

    //Posting Comment & up/downvoting
    void comment(string, string);
    void upvote();
    void downvote();

};