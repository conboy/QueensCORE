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
    const char* s;


public:
    PostCollection(const char* dir);

    int createPostDB();

    int createPostTable();

    int storeToPostDB(Post post);

    int selectPostDataEvent(int event);

    int selectPostDataOwner(string ownerName);

    int deleteData(string column, string del);

    int selectPostDataAll();

    int updateVotes(string title, int up, int down);

    int storeVectorPosts(vector<Post> post);

    int deleteData(int event);
};

vector<Post> getSelectedData();

#endif //QUEENSCORE_POST_COLLECTION_H
