#include <iostream>
#include <string>
#include "Fooditem.h"

using namespace std;

//Burada Fooditem ve singlyFoodList siniflarinin fonksiyon govdeleri olusturuldu.


Fooditem::Fooditem(){
	name = "yemek";
	itemID = 0;
	price = 0.00;
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
	
	Fooditem* previous = head;
	while (previous->next != NULL)
	{
		if ((name.compare(previous->next->getName()) == 0) && (previous->next->getID() == id))
		{
			Fooditem* temp = previous->next;
			previous->next = previous->next->next;
			delete temp;
			return;
		}
		previous = previous->next;
	}
	cout << "\n" << id << "\n" << nam << " Aradiginiz yemek menude bulunmamaktadir!" << endl;
}

void SinglyFoodList::addFront(const double& prc,const string& nam, const int& id){
	Fooditem* nFood = new Fooditem;							
	nFood->setName(nam);
	nFood->setItemID(id);
	nFood->setPrice(prc);
	nFood->next = head;								
	head = nFood;
}