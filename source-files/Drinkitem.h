#pragma once
#include <iostream>
#include <string>
#include "Menuitem.h"
using namespace std;
//Menuitem class indan miras alarak Drinkitem classini tanimliyoruz
//Elimizde bir yemek listesi olacagindan Drinkitem classindan olusturulacak nesnelerimizi 
//SingleLinkedList yani dinamik veri yapisiyla tutacagiz.(Main icerisinde elimizdeki txt dosyasindan verileri cekip bellekte tutacak.)

class Drinkitem : public Menuitem {
public:
	Drinkitem* next;
	Drinkitem();
	Drinkitem(const string& nam, const int& id);
};

class SinglyDrinkList : public Drinkitem {
public:
	Drinkitem* head;
	SinglyDrinkList();
	~SinglyDrinkList();
	bool empty() const;
	//void addFront(const double& prc, const string& nam, const int& id);
	void insertOrdered(Drinkitem* nDrink, Drinkitem* previousNode);
	//insertOrdered(newNode, list.head); seklinde yollanmalý unutma
	void removeOrdered(const int& id, const string& nam);
};