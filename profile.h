//
// Created by ebutl on 2022-10-25.
//

#ifndef PROFILES_PROFILE_H
#define PROFILES_PROFILE_H

#include <string>
#include <vector>
#include <iostream>
#include "post_class.h"

using namespace std;
//error checking classes

class MissingUser : public std::exception{
public:
    char *what();
};

class MissingEmail : public std::exception{
public:
    char *what();

};

class WrongEmail : public std::exception{
public:
    char *what();

};

class MissingPassword : public std::exception{
public:
    char *what();
};

class profile {
private:
    string email;
    string username;
    string password;
    vector<Post> selfPost;


public:
    //constructors
    profile(string mail, string user, string pass); //add field for image?

    //accessors
    string get_username();
    string get_email();
    string get_password();
    vector<Post>get_self();


    //profile altering functions
    int change_username();
    int change_password();
    //cannot change email adress, as account is made based on email
    void makePost(string y, string z);
};


#endif //PROFILES_PROFILE_H