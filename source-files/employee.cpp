#include <iostream>
#include "employee.h"
#include <string.h>


employee::employee(const int* userNo, const char* userName, const char* userEmail)
                : user(userNo, userName, userEmail){
}

employee::~employee(){}

void employee::displayInfo() const {
    user::displayInfo();
    
}