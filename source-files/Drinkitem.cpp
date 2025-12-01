#include <iostream>
#include <string>
#include "Drinkitem.h"

using namespace std;

//Burada Drinkitem ve SinglyDrinkList siniflarinin fonksiyon govdeleri olusturuldu.


Drinkitem::Drinkitem() {};

Drinkitem::Drinkitem(const string& nam, const int& id) {
	name = nam;
	itemID = id;
}

SinglyDrinkList::SinglyDrinkList() {
	head = NULL;
}

SinglyDrinkList::~SinglyDrinkList() {}

bool SinglyDrinkList::empty()const {
	return head == NULL;
}
void SinglyDrinkList::removeOrdered(const int& id, const string& nam) {
	if (empty())
	{
		cout << "Menude icecek bulunmamaktadýr!";
		return;
	}

	if ((nam.compare(head->getName()) == 0) && (head->getID() == id))
	{
		Drinkitem* temp = head;
		head = head->next;
		delete temp;
		return;
	}

	Drinkitem* previousNode = head;
	while (previousNode->next != NULL)
	{
		if ((name.compare(previousNode->next->getName()) == 0) && (previousNode->next->getID() == id))
		{
			Drinkitem* temp = previousNode->next;
			previousNode->next = previousNode->next->next;
			delete temp;
			return;
		}
		previousNode = previousNode->next;
	}
	cout << "\n" << id << "\n" << nam << " Silmek istediginiz icecek menude bulunmamaktadir!" << endl;
}

void SinglyDrinkList::insertOrdered(Drinkitem* nDrink, Drinkitem* previousNode) {

	if (previousNode->next == NULL || nDrink->getID() <= previousNode->next->getID())
	{
		nDrink->next = previousNode->next;
		previousNode->next = nDrink;
		return;
	}
	SinglyDrinkList::insertOrdered(nDrink, previousNode->next);
}
//insertOrdered(newNode, list.head); seklinde yollanmalý unutma






//void SinglyDrinkList::addFront(const double& prc,const string& nam, const int& id){
//	Drinkitem* nDrink = new Drinkitem;							
//	nDrink->setName(nam);
//	nDrink->setItemID(id);
//	nDrink->setPrice(prc);
//	nDrink->next = head;								
//	head = nDrink;
//}