//
// Created by ebutl on 2022-10-25.
//

#include "profile.h"
//errors
char* MissingUser::what(){
    return (char*)"Please input a username";
}

char* MissingEmail::what(){
    return (char*)"Please input an email address";
}

char* MissingPassword::what() {
    return (char *) "Please input a password";
}

char* WrongEmail::what(){
    return (char *) "Please enter a valid email ending in \"@queensu.ca\"";
}

//----------------------------------------------------------------------------------------------------------------------

//constructors
profile::profile(string mail, string user, string pass) {
    int spec = 0;
    int nums = 0;
    int count = 0;

    string num = "1234567890";

    //check that there is something entered into each field
    if(mail == "\0" || mail == "\n") throw MissingEmail();
    if(user == "\0" || user == "\n") throw MissingUser();
    if(pass == "\0" || pass == "\n") throw MissingPassword();

    //verify that the entered email is of "@queensu.ca" domain
    if(mail.substr(mail.length() - 11) != "@queensu.ca") throw WrongEmail();
    if(user.size() < 3 || user.size() > 12) throw WrongUser();

    for(int i = 0; i < pass.size(); i++){
        if(pass[i] == '#' || pass[i] == '!' || pass[i] == '?') {
            spec++;
            count++;
        } //verify special characters

            //verify numbers in password

        else count++; //verify some character does exist, update count
    }

    if(count > 12 || count < 3 || nums < 2 || spec < 1){
        throw WrongPass();
    }

    email = mail;
    username = user;
    password = pass;
    //field to store image

    //store in sql
}

//---------------------------------------------------------------------------------------------------------------------

//accessors
string profile::get_username(){ return username;}

string profile::get_email() { return email;}

string profile::get_password() { return password;}

vector<Post> profile::get_self(){ return selfPost;}

//---------------------------------------------------------------------------------------------------------------------

//field editors
//add posts made by profile to its log
void profile::makePost(string y, string z) {
    Post toAdd = Post(username, y, z);
    selfPost.push_back(toAdd);}





//change the username of user
int profile::change_username(string newUser) {
    if(newUser.size() < 3 || newUser.size() > 12) throw WrongUser();

    else{ //change username if verified
        username = newUser;
    }

}
//change the password of user
int profile::change_password(string newPass) {
    int count;
    int spec;
    for(int i = 0; i < newPass.size(); i++){
        if(newPass[i] == '#' || newPass[i] == '!' || newPass[i] == '?') {
            spec++;
            count++;
        } //verify special characters

            //verify numbers in password

        else count++; //verify some character does exist, update count
    }

}

