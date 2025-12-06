#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "user.h"

//ordera da bağlı

class customer : public user {
private: //protected?
    char* address;
    char* orders[];

public:
    customer(const int* userNo,const char* userName, const char* userEmail, const char* userAddress);
    ~customer();
    
    const char* getaddress() const;
    /*
    void set(const char* newAddress){
        address = newAddress;
    }      */

    void displayInfo() const override;
    //kopyalicak mı
};


#endif


