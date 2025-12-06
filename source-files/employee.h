#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "user.h"

class employee : public user {
public:
    employee(const int* userNo, const char* userName, const char* userEmail);
    ~employee();

    void displayInfo() const override;
    
};

#endif