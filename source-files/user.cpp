#include <iostream>
#include <string.h>
#include "User.h"
using namespace std;


User::User() {
	userID = 0;
	userName = "John Doe";
	userEmail = "john.doe@gmail.com";
}

User::~User(){
	
}
User::User(int newUserId, string newUserName, string newUserEmail) {
	this->setUserID(newUserId);
	this->setUserName(newUserName);
	this->setUserEmail(newUserEmail);
}

void User::setUserName(const string& newUserName) {
	userName = newUserName;
}
void User::setUserEmail(const string& newUserEmail) {
	userEmail = newUserEmail;
}
void User:: setUserID(const int& newUserId){
	userID = newUserId;
}

int User::getUserID() const{
	return userID;
}
string User::getUserName() const {
	return userName;
}
string User::getUserEmail() const{
	return userEmail;
}
void User::displayInfo(){
	cout << "Kullanici bilgileri: " << endl
		<< "ID: " << getUserID() << endl
		<< "Name: " << getUserName() << endl
		<< "Email: " << getUserEmail() << endl;
}
