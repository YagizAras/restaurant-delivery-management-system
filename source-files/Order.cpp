#include <iostream>
#include <string.h>
#include <iomanip>
#include "Order.h"

using namespace std;

Order::Order() {
	orderCapacity = 5;
	currentOrderSize = 0;
	totalPrice = 0.00;
	orderStatus = "Siparisiniz Hazirlaniyor...";
	itemList = new Menuitem* [orderCapacity];
	for (int i = 0; i < orderCapacity; ++i) {
		itemList[i] = nullptr;
	}
}
Order::~Order(){
	delete[] itemList;
}

void Order::addItemToOrder(int newItemID, Menuitem** restaurantMenu) {
	if (currentOrderSize >= orderCapacity)
	{
		orderCapacity *= 2;
		Menuitem** tempOrder = new Menuitem * [orderCapacity];
		for (size_t i = 0; i < currentOrderSize; i++)
		{
			tempOrder[i] = itemList[i];
		}
		delete[] itemList;
		itemList = tempOrder;
		tempOrder = nullptr;
	}
	int i = 0;
	while (restaurantMenu[i] != nullptr)
	{
		if (restaurantMenu[i]->getItemID() == newItemID)
		{
			if (restaurantMenu[i]->getItemType() == 'F')
			{
				itemList[currentOrderSize] = restaurantMenu[i];
				currentOrderSize++;
				return;
			}
			else if (restaurantMenu[i]->getItemType() == 'D')
			{
				itemList[currentOrderSize] = restaurantMenu[i];
				currentOrderSize++;
				return;
			}
		}
		i++;
	}
	cout << "Siparis vermek istediginiz urun restorant menusunde bulunmamaktadir!" << endl;
	this->showOrder();
}

void Order::removeItemFromOrder(int itemID){
	for (size_t i = 0; i < currentOrderSize; i++)
	{
		if (itemList[i]->getItemID() == itemID) {
			cout << itemList[i]->getItemID() << " "
				<< itemList[i]->getItemType() << " "
				<< itemList[i]->getItemPrice() << " "
				<< itemList[i]->getItemName()
				<< " --> Urunu siparisten silinmistir! " << endl;
		
			//silme yapmýyoruz silinecek olaný sona kaydýrýp son elemaný nullptr yapýyorum
			//çünkü zaten restoran classý item listi tutyor (swallow copy)
			for (size_t j = i; j < currentOrderSize - 1; j++)
			{
				itemList[j] = itemList[j + 1];
			}
			itemList[currentOrderSize - 1] = nullptr;
			currentOrderSize--;
			return;
		}
	}
	cout << endl;
	cout << "Silmek istediginiz urun sepetinizde bulunmamaktadir!";
	cout << endl;
	this->showOrder();
}

void Order::calculateTotalPrice(){
	totalPrice = 0.00;
	for (size_t i = 0; i < currentOrderSize; i++)
	{
		totalPrice += itemList[i]->getItemPrice();

	}
	cout << "Toplam siparis tutari: " << totalPrice << endl;
}

string Order::getOrderStatus() const{
	return orderStatus;
}
double Order::getTotalPrice(){
	return totalPrice;
}
void Order::updateStatusReady(){
	orderStatus = "Siparisiniz Teslim Edilmistir.";
}

void Order::calculateDiscountForItem(){
	if (itemList == nullptr) return;


	for (size_t i = 0; i < currentOrderSize; i++)
	{
		itemList[i]->calculateDiscount();
	}

	this->calculateTotalPrice();
}

void Order::showOrder(){	
	double tempPrice = 0;
	cout << endl;
	cout << "Siparis detaylari: " << endl;
	if (currentOrderSize == 0) {
		cout << "Sepetiniz Bostur"<< endl;
	}
	else{
		for (size_t i = 0; i < currentOrderSize; i++)
		{
			orderStatus = "Siparisiniz Hazirlaniyor...";
			cout << "Urun ID: " << itemList[i]->getItemID() << " "
				<< "Urun Adi: " << itemList[i]->getItemName() << " "
				<< "Urun Fiyati: " << itemList[i]->getItemPrice() << " "
				<< "Urun Turu: " << itemList[i]->getItemType() << endl;
			
			
			cout << "Urunun Indirimli Fiyati: " << itemList[i]->calculateDiscount() << endl;
			tempPrice = tempPrice + itemList[i]->calculateDiscount();
			cout << endl;

			
		}

		this->calculateTotalPrice();
		//cout << "Siparis durumu: " << this->getOrderStatus() << endl;
		cout << "Indirimsiz Toplam tutar: " << this->getTotalPrice() << endl;
		cout << "Indirimli Toplam tutar: " << tempPrice;
		cout << endl;
	}	
}

void Order::setDeliveryPersonName(string DelPerNam) {
	deliveryPersonName = DelPerNam;
}
string Order::getDeliveryPersonName(){
	return deliveryPersonName;
}


int Order::getCurrentOrderSize() const{
	return currentOrderSize;
}
int Order::getOrderCapacity() const{
	return orderCapacity;
}