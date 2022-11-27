

#ifndef PROFILES_PROFILECOLLECTION_H
#define PROFILES_PROFILECOLLECTION_H

#include <string>
#include <vector>
#include "profile.h"
#include "sqlite3.h"

using namespace std;


class profileCollection {

    //how do we initalize database?

    int create_profileDB(const char *dbName);
    int createProfileTable();
    int storeToProfileDB(profile profile); //how is username passed? alter user create to include storeToPRofile?

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
