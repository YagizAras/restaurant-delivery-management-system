#include <iostream>
#include <string>
#include "Fooditem.h"

using namespace std;

//Burada Fooditem ve singlyFoodList siniflarinin fonksiyon govdeleri olusturuldu.


Fooditem::Fooditem() {};

Fooditem::Fooditem(const string& nam, const int& id){
	name = nam;
	itemID = id;
}

SinglyFoodList::SinglyFoodList() {
	head = NULL;
}

SinglyFoodList::~SinglyFoodList(){}

bool SinglyFoodList::empty()const {
	return head == NULL;
}
void SinglyFoodList::removeOrdered(const int& id,const string& nam){
	if (empty())
	{
		cout << "Menude yemek bulunmamaktadýr!";
		return;
	}

	if ((nam.compare(head->getName()) == 0) && (head->getID() == id))
	{
		Fooditem* temp = head;
		head = head->next;
		delete temp;
		return;
	}
	
	Fooditem* previousNode = head;
	while (previousNode->next != NULL)
	{
		if ((name.compare(previousNode->next->getName()) == 0) && (previousNode->next->getID() == id))
		{
			Fooditem* temp = previousNode->next;
			previousNode->next = previousNode->next->next;
			delete temp;
			return;
		}
		previousNode = previousNode->next;
	}
	cout << "\n" << id << "\n" << nam << " Silmek istediginiz yemek menude bulunmamaktadir!" << endl;
}

void SinglyFoodList::insertOrdered(Fooditem* nFood,Fooditem* previousNode) {

	if (previousNode->next == NULL || nFood->getID() <= previousNode->next->getID())
	{
		nFood->next = previousNode->next;
		previousNode->next = nFood;
		return;
	}
	SinglyFoodList::insertOrdered(nFood,previousNode->next);
}
//insertOrdered(newNode, list.head); seklinde yollanmalý unutma






//void SinglyFoodList::addFront(const double& prc,const string& nam, const int& id){
//	Fooditem* nFood = new Fooditem;							
//	nFood->setName(nam);
//	nFood->setItemID(id);
//	nFood->setPrice(prc);
//	nFood->next = head;								
//	head = nFood;
//}