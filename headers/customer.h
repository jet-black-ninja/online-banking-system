#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include "person.h"

class Customer:public Person{
private: 
    float balance;

public:
    Customer():Person() , balance(0){}
    Customer(int ID, const char* name , const char* address, long int phone , TimeStamp dob , const char* pass , float balance):
    Person(ID, name ,address, phone , dob, pass ) ,balance(balance){};

    Customer(const Customer& other):Person(other){
        this->balance = other.balance;
    }

    float getBalance() const;
    void showDetails() const;
    void deposit(float);
    void withdraw(float);

};
#endif //CUSTOMER_H