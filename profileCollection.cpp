//
// Created by ebutl on 2022-10-25.
//

#include "profileCollection.h"

using namespace std;

void profileCollection::makeProfile(string x, string y, string z) {
    int dupes = 0;

    for(int i = 0; i < profiling.size(); i++){
        if(profiling[i].get_password() == z){
            cout << "Password is already in use" << endl;
            dupes = 1;
            i = profiling.size();
        }

        if(profiling[i].get_email() == x){
            cout << "email is already used by another account" << endl;
            dupes = 1;
            i = profiling.size();
        }

        if(profiling[i].get_username() == y){
            cout << "Username is already used by another account" << endl;
            dupes = 1;
            i = profiling.size();
        }
    }
    if(dupes == 0){
        profile a = profile(x, y, z);
        profiling.push_back(a);
        cout << "Profile created successfully" << endl;
    }




}
