#pragma once
#include <string>
using namespace std;


class User {
public:
	
    User();
    User(int newUserId, string newUserName, string newUserEmail);
    virtual ~User();
    
    int getUserID()const;
    string getUserName()const;
    string getUserEmail()const;
	void setUserID(const int& newUserId);
	void setUserName(const string& newUserName);
	void setUserEmail(const string& newUserEmail);

    virtual void displayInfo();

private:
    int userID;
    string userName;
    string userEmail;

};
