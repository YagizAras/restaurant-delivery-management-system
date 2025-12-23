#pragma once

#include <string>
#include "User.h"
#include "Restaurant.h"
#include "Order.h"

using namespace std;

class Customer : public User {

public:
    Customer(int newUserID, string newUserName, string newUserEmail, string newCustomerAddress);
    ~Customer();


    void extendOrderList();
    void addNewOrder(int menuID,Menuitem** restaurantMenu);


	Order** getOrderList();
    
	int getCurrentOrderSize() const;
    string getCustomerAddress();
    void setCustomerAddress(const string& newCustomerAddress);
    void displayInfo() override;

private:
    Order** orderList;
	int orderCount, currentOrderSize;
    string customerAddress;
	char isOrderContinue;
};



