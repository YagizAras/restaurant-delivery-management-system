#pragma once

#include <string>
#include "Menuitem.h"
#include "Fooditem.h"
#include "Drinkitem.h"
#include "DeliveryPerson.h"
#include "Restaurant.h"

class Order {
public:
    Order();
    ~Order();

    string getOrderStatus() const;
    double getTotalPrice();
	int getCurrentOrderSize() const;
	int getOrderCapacity() const;

    void addItemToOrder(int newItemID, Menuitem** restaurantMenu);
    void removeItemFromOrder(int itemID);                                  
	
    void calculateTotalPrice();                                  
    void updateStatusReady();                         
 
	void calculateDiscountForItem();
	void assignDeliveryPerson(DeliveryPerson* newDeliveryPerson); 
	void showOrder();                                             

    void setDeliveryPersonName(string DelPerNam);
    string getDeliveryPersonName();
private:
    Menuitem** itemList;            
    string orderDate;                   
    string orderStatus;                 

    string deliveryPersonName;

	double totalPrice;                 
    int itemCount;       
    int currentOrderSize,orderCapacity;
    
    DeliveryPerson* deliveryPerson;     
};