#include <iostream>
#include "Employee.h"
#include <string.h>

Employee::Employee(int newUserId, string newUserName, string newUserEmail):User(newUserId, newUserName, newUserEmail){

}

Employee::~Employee(){}