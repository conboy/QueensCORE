

#ifndef PROFILES_PROFILECOLLECTION_H
#define PROFILES_PROFILECOLLECTION_H

#include <string>
#include <vector>
#include "profile_class.h"
#include "sqlite3.h"


using namespace std;

class DbProfileFail : public std::exception {
public:
    char *what();
};
class profile_collection {
private:
    const char* s;
public:
    //how do we initalize database?
    profile_collection(const char *directory);
    int create_profileDB();
    int createProfileTable();
    int storeToProfileDB(profile_class profile); //how is username passed? alter user create to include storeToPRofile?

    string checkForProfile(const string username, const string password);

    //function that gets all fields for use by website:
    /*
     * takes in email and password.
     * gets username of related email and password
     *
     * gets username ascoiated with this email and password
     * gets all posts made by user with ascociated username
     *
     * returns posts and usernme in form to be handled by websockets/javascript
     */


};


#endif //PROFILES_PROFILECOLLECTION_H
