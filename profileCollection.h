

#ifndef PROFILES_PROFILECOLLECTION_H
#define PROFILES_PROFILECOLLECTION_H

#include <string>
#include <vector>
#include "profile.h"
#include "sqlite3.h"

using namespace std;


class profileCollection {

    int create_profileDB(const char *dbName);
    int createProfileTable();
    int storeToProfileDB(profile profile);


};


#endif //PROFILES_PROFILECOLLECTION_H
