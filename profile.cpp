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
    if(mail == "\0" || mail == "\n") throw MissingEmail();
    if(user == "\0" || user == "\n") throw MissingUser();
    if(pass == "\0" || pass == "\n") throw MissingPassword();
    if(mail.substr(mail.length() - 11) != "@queensu.ca") throw WrongEmail();

    email = mail;
    username = user;
    password = pass;
    //selfPost set to empty vector in fields
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
int profile::change_username() {
    string new_user;
    string verify;

    cout << "Please enter your password: ";
    cin >> verify;

    if(verify == password){//if password verified, username is changed
        cout << "Please enter your new username: ";
        cin >> new_user;
        username = new_user;
        return 0;

    }
    else if(verify == "0"){ //indicates user wnants to end username changing
        return 0;
    }

    else{ //loops to continue to attemot to change username
        cout<< "Incorrect password given. Try again. To end process, enter 0";
        change_username();
    }

}
//change the password of user
int profile::change_password() {
    string new_password;
    string verify;

    cout << "Please enter your current password: ";
    cin >> verify;

    if(verify == password){ //if correct password given, passord is changed by user
        cout << "Please enter your new password: ";
        cin >> new_password;

        if(password == new_password){ //checks for duplicate password
            cout << "New password cannot be same as old password. Ending process";
            return 0;
        }

        else{ //if not duplicate, changes to given password
            password = new_password;
            return 0;
        }
    }
    else if(verify == "0"){ //indicates user wants to give up trying to change password
        return 0;
    }

    else{ //incorrect password given, loops to try again
        cout<< "Incorrect password given. Try again. To end process, enter 0";
        change_password();
    }

}

