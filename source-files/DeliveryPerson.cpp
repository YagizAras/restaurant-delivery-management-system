#include <iostream>
#include <string>
#include "DeliveryPerson.h"

using namespace std;


DeliveryPerson::DeliveryPerson(int newUserID, string newUserName, string newUserEmail):Employee(newUserID, newUserName, newUserEmail){
	setUserID(newUserID);
	setUserName(newUserName);
	setUserEmail(newUserEmail);
}
DeliveryPerson::~DeliveryPerson(){

}
void DeliveryPerson:: displayInfo(){
	cout << "Calisan bilgileri: " << endl
		<< "ID: " << getUserID() << endl
		<< "Name: " << getUserName() << endl
		<< "Email: " << getUserEmail() << endl;
}