//
// Created by jmcor on 11/29/2022.
//

#include "profile_class.h"
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

char* passConfirmError::what(){
    return (char *) "Password confirmation does not match";
}

//----------------------------------------------------------------------------------------------------------------------

//constructors
profile_class::profile_class(string mail, string user, string pass, string confirmPass) {
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
    if(user.size() < 3 || user.size() > 12) throw BadUser();

    for(int i = 0; i < pass.size(); i++){
        if(pass[i] == '#' || pass[i] == '!' || pass[i] == '?') {
            spec++;
            count++;
        } //verify special characters
        else if (pass[i] == '0' || pass[i] == '1' || pass[i] == '2' || pass[i] == '3' || pass[i] == '4' || pass[i] == '5' || pass[i] == '6' || pass[i] == '7' ||pass[i] == '8' || pass[i] == '9') {
            nums++;
            count++;
        }
            //verify numbers in password

        else count++; //verify some character does exist, update count
    }

    if(count > 12 || count < 3 || nums < 2 || spec < 1){
        throw BadPassword();
    }

    if (pass != confirmPass) {
        throw passConfirmError();
    }

    email = mail;
    username = user;
    password = pass;
    confirmPassword = confirmPass;
    //field to store image

    //store in sql
}

//---------------------------------------------------------------------------------------------------------------------

//accessors
string profile_class::get_username(){ return username;}

string profile_class::get_email() { return email;}

string profile_class::get_password() { return password;}

string profile_class::get_confirmPassword() { return confirmPassword;}


//---------------------------------------------------------------------------------------------------------------------


//change the username of user
int profile_class::change_username(string newUser) {
    if(newUser.size() < 3 || newUser.size() > 12) throw BadUser();

    else{ //change username if verified
        username = newUser;
    }
    return 0;
}
//change the password of user
int profile_class::change_password(string newPass) {
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
    return 0;
}

