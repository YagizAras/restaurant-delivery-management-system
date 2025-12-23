#pragma once
#include "User.h"
#include <string>
using namespace std;


class Employee : public User {
public:
	Employee(int newUserId, string newUserName, string newUserEmail);
	~Employee();

	void displayInfo()override = 0;
};
