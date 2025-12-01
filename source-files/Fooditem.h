#pragma once
#include <iostream>
#include <string>
#include "Menuitem.h"
using namespace std;
//Menuitem class indan miras alarak Fooditem classini tanimliyoruz
//Elimizde bir yemek listesi olacagindan Fooditem classindan olusturulacak nesnelerimizi 
//SingleLinkedList yani dinamik veri yapisiyla tutacagiz.(Main icerisinde elimizdeki txt dosyasindan verileri cekip bellekte tutacak.)

class Fooditem: public Menuitem {
public:
	Fooditem* next;
	Fooditem();
	Fooditem(const string& nam,const int& id);
};

class SinglyFoodList : public Fooditem{
public:
	Fooditem* head;
	SinglyFoodList();
	~SinglyFoodList();
	bool empty() const;
	//void addFront(const double& prc, const string& nam, const int& id);
	void insertOrdered(Fooditem* nFood,Fooditem* previousNode);
	//insertOrdered(newNode, list.head); seklinde yollanmalý unutma
	void removeOrdered(const int& id, const string& nam);
};