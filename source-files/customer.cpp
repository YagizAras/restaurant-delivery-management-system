#include <iostream>
#include "customer.h"
#include <string.h>


customer::customer(const int*  userNo, const char* userName, const char* userEmail, const char* userAddress) 
                  : user(userNo, userName, userEmail){

                    size_t addressLength = strlen(userAddress) + 1;
                    address = new char[addressLength];
                    strcpy (address, userAddress);
                    
                  }

customer::~customer(){
    delete[] address;
}

const char* customer::getaddress() const {
        return address;
}

void customer::displayInfo() const{
    user::displayInfo();

    printf("Adres: %s\n",address); 
}
