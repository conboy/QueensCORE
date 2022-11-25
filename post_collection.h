//
// Created by liams on 2022-11-25.
//

#ifndef QUEENSCORE_POST_COLLECTION_H
#include "sqlite3.h"
#include "post_class.h"
#include <exception>

#define QUEENSCORE_POST_COLLECTION_H

using namespace std;

class DbPostFail : public std::exception {
public:
    char *what();
};
class post_collection {
private:

public:
    int createPostDB();
    int createPostTable();
    int storeToPostDB(Post post);
    vector<Post> getPostFromOwner(string postOwner);
    vector<Post> getPostFromEvent(eventType event);
    vector<Post> getAllPosts();
};


#endif //QUEENSCORE_POST_COLLECTION_H
