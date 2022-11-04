//
// Created by ebutl on 2022-10-25.
//

#ifndef PROFILES_PROFILECOLLECTION_H
#define PROFILES_PROFILECOLLECTION_H

#include <string>
#include <vector>
#include "profile.h"

using namespace std;


class profileCollection {
private:
    vector<profile> profiling;

public:
    void makeProfile(string x, string y, string z); //creates a profile, then adds it to profiling

};


#endif //PROFILES_PROFILECOLLECTION_H
