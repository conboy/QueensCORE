//
// Created by liams on 2022-11-25.
//

#ifndef QUEENSCORE_POST_COLLECTION_H
#include "sqlite3.h"
#include "post_class.h"


#define QUEENSCORE_POST_COLLECTION_H

using namespace std;



class DbPostFail : public std::exception {
public:
    char *what();
};
class PostCollection {
private:
    vector<Post> selectedPosts;
    int numSelectedPosts;
public:
    int createPostDB(const char *s);

    int createPostTable(const char *s);

    int storeToPostDB(const char *s, Post post);

    int selectPostData(const char *s);

    int deleteData(const char *s, string column, string del);

    void appendPost (Post post);

};

#endif //QUEENSCORE_POST_COLLECTION_H
