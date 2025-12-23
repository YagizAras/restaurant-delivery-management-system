#pragma once
#include "Employee.h"
#include <string>
using namespace std;

class DeliveryPerson : public Employee {
public:
	DeliveryPerson(int newUserID, string newUserName, string newUserEmail);
	~DeliveryPerson();

	void displayInfo()override;
};