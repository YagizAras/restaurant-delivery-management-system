#pragma once
#include <string>
#include "Employee.h"
#include "DeliveryPerson.h"
#include "Order.h"


class Manager : public Employee {
public:
    Manager();
    Manager(int newUserID, string newUserName, string newUserEmail);
    ~Manager();


    void createEmployeeList(string link);
    void attachDeliveryPerson(Order* currentOrder);
    void showEmployeeList();
    void addEmployee(int newUserID, string newUserName, string newUserEmail);
    void removeEmployee(int empID);
    void applyToTxt(string link);
    void displayInfo()override;


private:
    int employeeListSize, currentEmployeeSize;
    DeliveryPerson** employeeList;

};