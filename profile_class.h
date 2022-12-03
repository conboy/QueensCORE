//
// Created by ebutl on 2022-10-25.
//

#ifndef PROFILES_PROFILE_H
#define PROFILES_PROFILE_H

#include <string>
#include <vector>
#include <iostream>
#include "sqlite3.h"

using namespace std;
//error checking classes

//error classes for missing inputs
class MissingUser : public std::exception{
public:
    char *what();
};
class MissingEmail : public std::exception{
public:
    char *what();

};
class MissingPassword : public std::exception{
public:
    char *what();
};

//error classes for invlaid fields:
class WrongEmail : public std::exception{
public:
    char *what();

};
class BadPassword : public std::exception{
public:
    char *what();

};
class BadUser : public std::exception{
public:
    char *what();

};
class passConfirmError : public std::exception{
public:
    char *what();

};

class profile_class {
private:
    string email;
    string username;
    string password;
    string confirmPassword;


public:

    //constructors
    profile_class(string mail, string user, string pass, string confirmPass); //add field for image?

    //accessors
    string get_username();
    string get_email();
    string get_password();
    string get_confirmPassword();


    //profile_class altering functions
    int change_username(string newProfile);
    int change_password(string newPass);
    //cannot change email adress, as account is made based on email

    //to be called to make a post; gets title, comment, and type, auto adds user ID
    void makePost(string x, string y, int z);
    //gets all post with user's ID
};


#endif //PROFILES_PROFILE_H
