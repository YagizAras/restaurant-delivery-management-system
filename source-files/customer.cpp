#include <iostream>
#include <string>
#include "Customer.h"
#include "Menuitem.h"

using namespace std;


Customer::Customer(int newUserID, string newUserName, string newUserEmail, string newCustomerAddress)
    : User(newUserID, newUserName, newUserEmail) {

    this->setCustomerAddress(newCustomerAddress);
    orderCount = 5;
    currentOrderSize = 0;
    isOrderContinue = 'D';
    orderList = new Order * [orderCount];

}


Customer::~Customer() {
    for (int i = 0; i < currentOrderSize; i++) {
        if (orderList[i] != nullptr) {
            delete orderList[i];
        }
    }
    delete[] orderList;

}

void Customer::addNewOrder(int menuID,Menuitem** restaurantMenu) {
    extendOrderList();
    orderList[currentOrderSize] = new Order();

    bool flag;
    orderList[currentOrderSize]->addItemToOrder(menuID, restaurantMenu);
    
    while (true)
    {   

        orderList[currentOrderSize]->showOrder();
        cout << "Sepete urun eklemek icin 'E',sepetten urun silmek icin 'S', sepeti onaylamak icin 'B' yaziniz: ";
        cin >> isOrderContinue;
        
            
        if (isOrderContinue == 'E' || isOrderContinue == 'e') {
            cout << "Eklemek istediginiz urunun ID sini giriniz: ";
            cin >> menuID;
            orderList[currentOrderSize]->addItemToOrder(menuID, restaurantMenu);

        }
        else if (isOrderContinue == 'S' || isOrderContinue == 's')
        {  
			cout << "Silmek istediginiz urunun ID sini giriniz: ";
			cin >> menuID;
			orderList[currentOrderSize]->removeItemFromOrder(menuID);
        }
        else if(isOrderContinue == 'B' || isOrderContinue == 'b') {
            cout << endl;
			cout << "Siparisiniz onaylandi. Tesekkurler!" << endl;
            currentOrderSize++;
            return;
        }
        else
        {
			cout << "Gecersiz islem!" << endl;
            continue;
        }
    }
}


void Customer::extendOrderList(){
    if (currentOrderSize >= orderCount) {
        orderCount *= 2;
        Order** tempOrderList = new Order * [orderCount];
        for (size_t i = 0; i < currentOrderSize; i++)
        {
            tempOrderList[i] = orderList[i];
        }

        for (size_t i = currentOrderSize; i < orderCount; i++)
        {
            tempOrderList[i] = nullptr;
        }
        delete[] orderList;
        orderList = tempOrderList;
        tempOrderList = nullptr;
    }
}


void Customer::setCustomerAddress(const string& newCustomerAddress) {
    customerAddress = newCustomerAddress;
}

string Customer::getCustomerAddress(){
    return customerAddress;
}

void Customer::displayInfo(){
    User::displayInfo();
    cout << "Address: " << getCustomerAddress() << endl;
}

Order** Customer::getOrderList(){
    return orderList;
}
int Customer::getCurrentOrderSize() const{
    return currentOrderSize;
}