#include <iostream>
#include <string>
#include <random>
#include <fstream>
#include "Manager.h"
#include "DeliveryPerson.h"

using namespace std;

Manager::Manager(int newUserID, string newUserName, string newUserEmail):Employee(newUserID, newUserName, newUserEmail) {
    employeeListSize = 5;
    currentEmployeeSize = 0;
    employeeList = new DeliveryPerson*[employeeListSize];
}

void Manager::createEmployeeList(string link) {
    int newUserID;
    string newUserName,newUserEmail;
    int i = 0;

    ifstream reFile;
    reFile.open(link);

    while (reFile >> newUserID >> newUserEmail) {
        getline(reFile >> ws, newUserName);
        this->addEmployee(newUserID, newUserName, newUserEmail);
    }
    reFile.close();
}


void Manager::addEmployee(int newUserID, string newUserName, string newUserEmail) {
    if (currentEmployeeSize >= employeeListSize) {
        employeeListSize = employeeListSize * 2;
        DeliveryPerson** tempEmployeeList = new DeliveryPerson*[employeeListSize];
        for (size_t i = 0; i < currentEmployeeSize; i++)
        {
            tempEmployeeList[i] = employeeList[i];
        }
        delete[] employeeList;
        employeeList = tempEmployeeList;
        tempEmployeeList = nullptr;
    }
    employeeList[currentEmployeeSize] = new DeliveryPerson(newUserID, newUserName,newUserEmail);
    currentEmployeeSize++;
}

void Manager::removeEmployee(int empID) {
    for (size_t i = 0; i < currentEmployeeSize; i++) {
        if (employeeList[i]->getUserID() == empID) {
            delete employeeList[i];
            for (int j = i; j < currentEmployeeSize - 1; j++) {
                //kaydýrdým
                employeeList[j] = employeeList[j + 1];
            }
            //son elemaný bosalttým
            employeeList[currentEmployeeSize - 1] = nullptr;
            currentEmployeeSize--;
			return;
        }
    }
	cout << "Silmek istediginiz eleman employee listesinde bulunmamaktadýr! ";
}
void Manager::applyToTxt(string link) {
    ofstream wrFile;
    wrFile.open(link);

    for (size_t i = 0; i < currentEmployeeSize; i++)
    {
        wrFile << employeeList[i]->getUserID() << " "
            << employeeList[i]->getUserEmail() << " "
			<< employeeList[i]->getUserName() <<  " "
            << endl;
    }

    wrFile.close();
}

void Manager::displayInfo() {
    cout << "Mudur bilgileri: " << endl
        << "ID: " << getUserID() << endl
        << "Name: " << getUserName() << endl
        << "Email: " << getUserEmail() << endl;
}

void Manager :: attachDeliveryPerson(Order* currentOrder) {

    int randomIndex = rand() % currentEmployeeSize;
    string holdEmpName = employeeList[randomIndex]->getUserName();

    if (currentOrder != nullptr) {
        currentOrder->setDeliveryPersonName(holdEmpName);
        cout << holdEmpName << endl;
    }
}
void Manager::showEmployeeList() {
    cout << "Employee Listesi: " << endl;
    for (size_t i = 0; i < currentEmployeeSize; i++) {
        cout << i + 1 << ". "
            << "ID: " << employeeList[i]->getUserID() << ", "
            << "Name: " << employeeList[i]->getUserName() << ", "
            << "Email: " << employeeList[i]->getUserEmail() << endl;
    }
}

Manager::~Manager() {
    for (int i = 0; i < currentEmployeeSize; i++) {
		if (employeeList[i] != nullptr)
            delete employeeList[i];
    }
    delete[] employeeList;
}