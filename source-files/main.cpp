#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Restaurant.h"
#include "Menuitem.h"
#include "Customer.h"
#include "Order.h"
#include "User.h"
#include "Manager.h"

//434366 Yaðýz ARAS
//434376 Ýlayda ATÝK
//Dönem Sonu OOP Proje Ödev Teslimi


using namespace std;

int main() {
	string enteranceValue;
	string customerName, customerEmail, customerAddress;
	string managerName, managerEmail;
	string employeeName, employeeEmail;

	srand(time(0));
	int randomCustomerID = rand() % 11 + 2000;
	int restaurantNumberChoice, managerNumberChoise;
	int itemID = 0;
	int OrderSizeHolder = 0;
	int employeeID = 0;


	Manager manager1(1001, "Admin1", "BellaNapoli@manager.com");
	Manager manager2(1002, "Admin2", "ElCaminoTacos@manager.com");
	Manager manager3(1003, "Admin3", "SakuraSushiWok@manager.com");
	Manager manager4(1004, "Admin4", "TheBurgerJoint@manager.com");
	Manager manager5(1005, "Admin5", "UrbanCoffee@manager.com");

	manager1.createEmployeeList("yfRestaurant1emp.txt");
	manager2.createEmployeeList("yfRestaurant2emp.txt");
	manager3.createEmployeeList("yfRestaurant3emp.txt");
	manager4.createEmployeeList("yfRestaurant4emp.txt");
	manager5.createEmployeeList("yfRestaurant5emp.txt");


	Restaurant restaurant1;
	Restaurant restaurant2;
	Restaurant restaurant3;
	Restaurant restaurant4;
	Restaurant restaurant5;
	Order** order1 = nullptr;




	restaurant1.createRestaurantMenu("zfBellaNapoli.txt");
	restaurant2.createRestaurantMenu("zfElCaminoTacos.txt");
	restaurant3.createRestaurantMenu("zfSakuraSushiWok.txt");
	restaurant4.createRestaurantMenu("zfTheBurgerJoint.txt");
	restaurant5.createRestaurantMenu("zfUrbanCoffee.txt");


	///// MÜÞTERÝ GÝRÝÞÝ /////
	while (true)
	{
		cout << endl;
		cout << endl;
		cout << "Restoran.com'a Hos Geldiniz!" << endl
			<< "1. \"Musteri\" " << endl
			<< "2. \"Yonetici\" " << endl
			<< "3. \"Cikis Yap\"" << endl
			<< "Lutfen giris turu seciniz:" << endl << endl;

		getline(cin >> ws, enteranceValue);


		if (enteranceValue.compare("Musteri") == 0)
		{
			cout << endl;
			cout << "Lutfen adinizi giriniz: ";
			getline(cin >> ws, customerName);
			cout << "Lutfen email adresinizi giriniz: ";
			getline(cin >> ws, customerEmail);
			cout << "Lutfen adresinizi giriniz: ";
			getline(cin >> ws, customerAddress);
			cout << endl;



			cout << "Musteri girisi yapiliyor..." << endl << endl;
			Customer customer1(randomCustomerID, customerName, customerEmail, customerAddress);
			customer1.displayInfo();
			Order** order1 = nullptr;

			while (true)
			{
				cout << endl;
				cout << "Yapmak istediginiz islemi seciniz:" << endl
					<< "1. Siparis Ver" << endl
					<< "2. Siparisleri goruntule" << endl
					<< "3. Oturumu Kapat" << endl;
				cout << "Seciminiz: ";
				cin >> restaurantNumberChoice;

				if (restaurantNumberChoice == 1)
				{
					while (true)
					{
						cout << endl;
						cout << "Restoranlarimiz:" << endl
							<< "1. Bella Napoli" << endl
							<< "2. El Camino Tacos" << endl
							<< "3. Sakura Sushi Wok" << endl
							<< "4. The Burger Joint" << endl
							<< "5. Urban Coffee" << endl
							<< "Lutfen restoran seciniz: ";
						cin >> restaurantNumberChoice;
						cout << endl;
						cout << endl;

						if (restaurantNumberChoice == 1)
						{
							cout << endl;
							restaurant1.showMenu();
							cout << endl;
							cout << "1.Sepeti Duzenle" << endl
								<< "2.Anasayfa Don" << endl
								<< "Lutfen yapmak istediginiz islemi seciniz: ";
							cin >> restaurantNumberChoice;

							if (restaurantNumberChoice == 1)
							{
								cout << "Lutfen sepete eklemek istediginiz urunun ID'sini giriniz: ";
								cin >> itemID;

								customer1.addNewOrder(itemID, restaurant1.getMenu());

								order1 = customer1.getOrderList();
								cout << "-----------------------------------------------------------------------------------------" << endl;
								cout << endl;
								cout << "Guncel Siparisleriniz: ";
								cout << endl;
								OrderSizeHolder = customer1.getCurrentOrderSize();
								
								order1[OrderSizeHolder - 1]->showOrder();
								cout << order1[OrderSizeHolder - 1]->getOrderStatus() << endl;
								cout << "Siparisinizle ilgilenen personel: ";
								manager1.attachDeliveryPerson(order1[OrderSizeHolder - 1]);
								cout << "-----------------------------------------------------------------------------------------" << endl;



								break;
							}

							else if (restaurantNumberChoice == 2)
							{
								break;
							}
							else
							{
								cout << "Gecersiz islem!" << endl;
								continue;
							}

							break;
						}
						else if (restaurantNumberChoice == 2)
						{
							cout << endl;
							restaurant2.showMenu();
							cout << endl;
							cout << "1.Sepeti Duzenle" << endl
								<< "2.Anasayfa Don" << endl
								<< "Lutfen yapmak istediginiz islemi seciniz: ";
							cin >> restaurantNumberChoice;

							if (restaurantNumberChoice == 1)
							{
								cout << "Lutfen sepete eklemek istediginiz urunun ID'sini giriniz: ";
								cin >> itemID;
								customer1.addNewOrder(itemID, restaurant2.getMenu());

								order1 = customer1.getOrderList();
								cout << "-----------------------------------------------------------------------------------------" << endl;
								cout << endl;
								cout << "Guncel Siparisleriniz: ";
								cout << endl;
								OrderSizeHolder = customer1.getCurrentOrderSize();

								order1[OrderSizeHolder - 1]->showOrder();
								cout << order1[OrderSizeHolder - 1]->getOrderStatus() << endl;
								cout << "Siparisinizle ilgilenen personel: " << endl;
								manager2.attachDeliveryPerson(order1[OrderSizeHolder - 1]);
								cout << "-----------------------------------------------------------------------------------------" << endl;

								break;
							}

							else if (restaurantNumberChoice == 2)
							{
								break;
							}
							else
							{
								cout << "Gecersiz islem!" << endl;
								continue;
							}

							break;
						}
						else if (restaurantNumberChoice == 3)
						{
							cout << endl;
							restaurant3.showMenu();
							cout << endl;
							cout << "1.Sepeti Duzenle" << endl
								<< "2.Anasayfa Don" << endl
								<< "Lutfen yapmak istediginiz islemi seciniz: ";
							cin >> restaurantNumberChoice;

							if (restaurantNumberChoice == 1)
							{
								cout << "Lutfen sepete eklemek istediginiz urunun ID'sini giriniz: ";
								cin >> itemID;
								customer1.addNewOrder(itemID, restaurant3.getMenu());

								order1 = customer1.getOrderList();
								cout << "-----------------------------------------------------------------------------------------" << endl;
								cout << endl;
								cout << "Guncel Siparisleriniz: " ;
								cout << endl;
								OrderSizeHolder = customer1.getCurrentOrderSize();


								order1[OrderSizeHolder - 1]->showOrder();
								cout << order1[OrderSizeHolder - 1]->getOrderStatus() << endl;
								cout << "Siparisinizle ilgilenen personel: " << endl;
								manager3.attachDeliveryPerson(order1[OrderSizeHolder - 1]);
								cout << "-----------------------------------------------------------------------------------------" << endl;



								break;
							}

							else if (restaurantNumberChoice == 2)
							{
								break;
							}
							else
							{
								cout << "Gecersiz islem!" << endl;
								continue;
							}

							break;
						}
						else if (restaurantNumberChoice == 4)
						{
							cout << endl;
							restaurant4.showMenu();
							cout << endl;
							cout << "1.Sepeti Duzenle" << endl
								<< "2.Anasayfa Don" << endl
								<< "Lutfen yapmak istediginiz islemi seciniz: ";
							cin >> restaurantNumberChoice;

							if (restaurantNumberChoice == 1)
							{
								cout << "Lutfen sepete eklemek istediginiz urunun ID'sini giriniz: ";
								cin >> itemID;
								customer1.addNewOrder(itemID, restaurant4.getMenu());

								order1 = customer1.getOrderList();
								cout << "-----------------------------------------------------------------------------------------" << endl;
								cout << endl;
								cout << "Guncel Siparisleriniz: ";
								cout << endl;
								OrderSizeHolder = customer1.getCurrentOrderSize();

								order1[OrderSizeHolder - 1]->showOrder();
								cout << order1[OrderSizeHolder - 1]->getOrderStatus() << endl;
								cout << "Siparisinizle ilgilenen personel: " << endl; 
								manager4.attachDeliveryPerson(order1[OrderSizeHolder - 1]);
								cout << "-----------------------------------------------------------------------------------------" << endl;



								break;
							}

							else if (restaurantNumberChoice == 2)
							{
								break;
							}
							else
							{
								cout << "Gecersiz islem!" << endl;
								continue;
							}

							break;
						}
						else if (restaurantNumberChoice == 5)
						{
							cout << endl;
							restaurant5.showMenu();
							cout << endl;
							cout << "1.Sepeti Duzenle" << endl
								<< "2.Anasayfa Don" << endl
								<< "Lutfen yapmak istediginiz islemi seciniz: ";
							cin >> restaurantNumberChoice;

							if (restaurantNumberChoice == 1)
							{
								cout << "Lutfen sepete eklemek istediginiz urunun ID'sini giriniz: ";
								cin >> itemID;
								customer1.addNewOrder(itemID, restaurant5.getMenu());

								order1 = customer1.getOrderList();
								cout << "-----------------------------------------------------------------------------------------" << endl;
								cout << endl;
								cout << "Guncel Siparisleriniz: ";
								cout << endl;
								OrderSizeHolder = customer1.getCurrentOrderSize();

								order1[OrderSizeHolder - 1]->showOrder();
								cout << order1[OrderSizeHolder - 1]->getOrderStatus() << endl;
								cout << "Siparisinizle ilgilenen personel: " << endl;
								manager5.attachDeliveryPerson(order1[OrderSizeHolder - 1]);
								cout << "-----------------------------------------------------------------------------------------" << endl;




								break;
							}

							else if (restaurantNumberChoice == 2)
							{
								break;
							}
							else
							{
								cout << "Gecersiz islem!" << endl;
								continue;
							}

							break;
						}
						else
						{
							cout << "Gecersiz restoran secimi!";
							cout << endl;
						}

					}
				}
				else if (restaurantNumberChoice == 2)
				{
					if (order1 == nullptr)
					{
						cout << endl;
						cout << "Herhangi bir siparisiniz bulunmamaktadir!" << endl;
					}
					for (size_t i = 0; i < OrderSizeHolder; i++)
					{
						cout << "-----------------------------------------------------------------------------------------" << endl;
						cout << endl << "ID: " << 1000 + i + 1 << " Numarali Siparis: " << endl;
						order1[i]->showOrder();
						order1[i]->updateStatusReady();
						cout << "Siparis Durumunuz: " << order1[i]->getOrderStatus()<< endl;
						cout << "Siparisinizle ilgilenen personel: " << order1[i]->getDeliveryPersonName() << endl;
						cout << "-----------------------------------------------------------------------------------------" << endl;
					}
				}
				else if (restaurantNumberChoice == 3)
				{
					cout << endl;
					cout << "Oturum kapatiliyor..." << endl;
					cout << customer1.getUserID() << " "
						<< customer1.getUserName() << " "
						<< customer1.getUserEmail() << " "
						<< "kimlik numarali musteri cikis yapti.";
					cout << endl;

					Order** tempOrder;
					tempOrder = order1;
					order1 = nullptr;

					break;
				}
				else
				{
					cout << "Gecersiz secim!" << endl;

				}
			}

		}





		///// YÖNETÝCÝ GÝRÝÞÝ /////
		else if (enteranceValue.compare("Yonetici") == 0)
		{
			int adminID = 0;
			Manager* activeManager = nullptr;
			Restaurant* activeRestaurant = nullptr;
			string activeTxtFile = "";
			string activeTxtEmployeeFile = "";

			while (true)
			{

				cout << "BellaNapoli Restoranti girisi(Admin1) " << endl
					<< "ElCaminoTacos Restoranti girisi(Admin2) " << endl
					<< "SakuraSushiWok Restoranti girisi(Admin3) " << endl
					<< "TheBurgerJoint Restoranti girisi(Admin4) " << endl
					<< "UrbanCoffee Restoranti girisi(Admin5) " << endl;
				cout << "Yonetici adinizi giriniz: ";

				getline(cin >> ws, managerName);
				cout << endl;


				if (managerName == "Admin1") adminID = 1;
				else if (managerName == "Admin2") adminID = 2;
				else if (managerName == "Admin3") adminID = 3;
				else if (managerName == "Admin4") adminID = 4;
				else if (managerName == "Admin5") adminID = 5;

				switch (adminID)
				{
				case 1:
					activeManager = &manager1;
					activeRestaurant = &restaurant1;
					activeTxtFile = "zfBellaNapoli.txt";
					activeTxtEmployeeFile = "yfRestaurant1emp.txt";
					cout << "BellaNapoli Yonetim Ekrani"<< endl;
					break;
				case 2:
					activeManager = &manager2;
					activeRestaurant = &restaurant2;
					activeTxtFile = "zfElCaminoTacos.txt";
					activeTxtEmployeeFile = "yfRestaurant2emp.txt";
					cout << "CaminoTacos Yonetim Ekrani" << endl;
					break;
				case 3:
					activeManager = &manager3;
					activeRestaurant = &restaurant3;
					activeTxtFile = "zfSakuraSushiWok.txt";
					activeTxtEmployeeFile = "yfRestaurant3emp.txt";
					cout << "SakuraSushiWok Yonetim Ekrani" << endl;
					break;
				case 4:
					activeManager = &manager4;
					activeRestaurant = &restaurant4;
					activeTxtFile = "zfTheBurgerJoint.txt";
					activeTxtEmployeeFile = "yfRestaurant4emp.txt";
					cout << "TheBurgerJoint Yonetim Ekrani" << endl;
					break;
				case 5:
					activeManager = &manager5;
					activeRestaurant = &restaurant5;
					activeTxtFile = "zfUrbanCoffee.txt";
					activeTxtEmployeeFile = "yfRestaurant5emp.txt";
					cout << "UrbanCoffee Yonetim Ekrani" << endl;
					break;
				default:
					cout << "Gecerli islem seciniz." << endl;
					continue; 
				}
				break;
			}


			if (activeManager != nullptr && activeRestaurant != nullptr)
			{
				cout << "Mudur girisi basarili..." << endl << endl;
				cout << "Mudur ekranina hos geldiniz!" << endl;
				activeManager->displayInfo(); 
				while (true)
				{


					
					cout << endl;
					cout << "Yonetim Paneli:" << endl
						<< "1. Menuyu Duzenle" << endl
						<< "2. Calisanlari Duzenle" << endl
						<< "3. Oturumu Kapat" << endl
						<< "Lutfen yapmak istediginiz islemi seciniz: ";

					cin >> restaurantNumberChoice;

					if (restaurantNumberChoice == 1)
					{
						string newItemName;
						int newItemID;
						double newItemPrice;
						char newItemType;

						cout << endl;
						cout << "1.Menuye Urun Ekle" << endl
							<< "2.Menuden Urun Sil" << endl
							<< "3.Ana Menuye Don" << endl
							<< "Lutfen yapmak istediginiz islemi seciniz: ";
						cout << endl;
						cin >> restaurantNumberChoice;
						if (restaurantNumberChoice == 1)
						{
							activeRestaurant->showMenu();
							cout << endl;
							cout << "1.Urun Ekle" << endl
								<< "2.Ana Menuye Don" << endl
								<< "Lutfen yapmak istediginiz islemi seciniz: ";
							cout << endl;

							cin >> restaurantNumberChoice;
							if (restaurantNumberChoice == 1)
							{
								activeRestaurant->showMenu();
								cout << endl;
								cout << "Eklenecek Urun Adi: ";
								getline(cin >> ws, newItemName);
								cout << "Eklenecek Urun ID: ";
								cin >> newItemID;
								cout << "Eklenecek Urun Fiyati: ";
								cin >> newItemPrice;
								cout << "Eklenecek Urun Turu (F: Yemek, D: Icecek): ";
								cin >> newItemType;
								cout << endl;
								if (newItemType == 'F' || newItemType == 'f') {
									activeRestaurant->addFoodItem(newItemName, newItemID, newItemPrice, 'F');
								}
								else if (newItemType == 'D' || newItemType == 'd') {
									activeRestaurant->addDrinkItem(newItemName, newItemID, newItemPrice, 'D');
								}

								activeRestaurant->applyToTxt(activeTxtFile);
								cout << endl << "Urun basariyla eklendi!" << endl;
								activeRestaurant->showMenu();

							}
							else if(restaurantNumberChoice == 2)
							{
								continue;
							}
							else
							{
								cout << "Gecersiz islem!" << endl;
								continue;
							}
						}
						else if (restaurantNumberChoice == 2)
						{
							activeRestaurant->showMenu();
							cout << "1.Urun Sil" << endl
								<< "2.Ana Menuye Don" << endl
								<< "Lutfen yapmak istediginiz islemi seciniz: ";
							cout << endl;
							cin >> restaurantNumberChoice;
							if (restaurantNumberChoice == 1)
							{
								activeRestaurant->showMenu();
								cout << "Silinecek Urun ID: ";
								cin >> newItemID;
								activeRestaurant->removeItem(newItemID);
								activeRestaurant->applyToTxt(activeTxtFile);
								cout << endl << "Urun basariyla silindi!" << endl;
								activeRestaurant->showMenu();
							}
							else if (restaurantNumberChoice == 2)
							{
								continue;
							}
							else
							{
								cout << "Gecersiz islem!" << endl;
								continue;
							}
						}

						else if (restaurantNumberChoice == 3)
						{
							continue;
						}
						else
						{
							cout << "Gecersiz islem!" << endl;
							continue;
						}

					}

					else if (restaurantNumberChoice == 2)
					{
						cout << "1.Calisan Ekle" << endl 
							<< "2.Calisan Cikar" << endl
							<< "3.Ana Menuye Don" << endl
							<< "Lutfen yapmak istediginiz islemi seciniz: ";
						cout << endl;
						cin >> restaurantNumberChoice;
						if (restaurantNumberChoice == 1)
						{	
							
							activeManager->showEmployeeList();
							cout << "1.Calisan Ekle" << endl
								<< "2.Ana Menuye Don" << endl
								<< "Lutfen yapmak istediginiz islemi seciniz: ";
							cin >> restaurantNumberChoice;
							cout << endl;
							if (restaurantNumberChoice == 1)
							{
								activeManager->showEmployeeList();
								cout << "Eklenecek Calisan ID: " << endl;
								cin >> employeeID;
								cout << "Eklenecek Calisan Adi: " << endl;
								getline(cin >> ws, employeeName);
								cout << "Eklenecek Calisan Email: " << endl;
								getline(cin >> ws, employeeEmail);
								activeManager->addEmployee(employeeID,employeeName, employeeEmail);
								activeManager->applyToTxt(activeTxtEmployeeFile);
								activeManager->showEmployeeList();
								cout << endl;
								cout << "Calisan basariyla eklendi!" << endl;
							}
							else if (restaurantNumberChoice == 2)
							{
								continue;
							}
							else
							{
								cout << "Gecersiz islem!" << endl;
								continue;
							}
						}
						else if (restaurantNumberChoice == 2)
						{
							activeManager->showEmployeeList();
							cout << "1.Calisan Sil" << endl
								<< "2.Ana Menuye Don" << endl
								<< "Lutfen yapmak istediginiz islemi seciniz: ";
							cin >> restaurantNumberChoice;
							cout << endl;

							if (restaurantNumberChoice == 1) 
							{
								activeManager->showEmployeeList();
								cout << "Silinecek Calisan ID: " << endl;
								cin >> employeeID;
								activeManager->removeEmployee(employeeID);
								activeManager->applyToTxt(activeTxtEmployeeFile);
								activeManager->showEmployeeList();
								cout << endl;
								cout << "Calisan basariyla silindi!" << endl;
							}
							else if (restaurantNumberChoice == 2) 
							{
								continue;
							}
							else
							{
								cout << "Gecersiz islem!" << endl;
								continue;
							}


						}
						else if (restaurantNumberChoice == 3)
						{
							continue;
						}
						else 
						{
							cout << "Gecersiz islem!" << endl;
							continue;
						}
					}

					else if (restaurantNumberChoice == 3)
					{
						cout << endl;
						cout << "Oturum kapatiliyor..." << endl;
						cout << activeManager->getUserID() << " "
							<< activeManager->getUserName() << " "
							<< activeManager->getUserEmail() << " "
							<< "kimlik numarali Yonetici cikis yapti.";
						cout << endl;
						break;
					}
					else
					{
						cout << "Gecersiz islem!" << endl;
						continue;
					}

				}
			
			}
		}

		else if (enteranceValue.compare("Cikis Yap") == 0 || enteranceValue == "3")
		{
			cout << "Restoran.com'dan cikis yapiliyor..." << endl;
			cout << "Gorusmek uzere!" << endl;
			return 0;
		}
		else
		{
			cout << "Gecersiz giris turu!" << endl;
			continue;
		}
		

	}
}