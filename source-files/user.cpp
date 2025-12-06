#include <iostream>
#include "user.h"
#include <string.h>


user::user(const int* userNo, const char* userName, const char* userEmail){
    userID = new int (*userNo);

    size_t nameLength = strlen(userName) + 1;
    name = new char[nameLength];
    strcpy (name, userName);

    size_t emailLength = strlen(userEmail) + 1;
    email = new char[emailLength];
    strcpy (email, userEmail);
}

user::~user(){
    delete userID;
    delete[] name;
    delete[] email;
}

void user::displayInfo() const {
    printf("ID: %d\n", userID);
    printf("Name: %s\n",name);
    printf("Email: %s\n", email);
}


const int* user::getuserID() const {
    return userID;
}

const char* user::getname() const {
    return name;
}

const char* user::getemail() const{
    return email;
}