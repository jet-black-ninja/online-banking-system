#include "headers/customer.h"
using namespace std;


float Customer::getBalance() const{
    return this->balance;
}
void Customer::deposit(float money){
    this->balance += money;
}
void Customer::withdraw(float money){
    this->balance -= money;
}
void Customer::showDetails() const{
    cout<<
        ID<<endl<<
        name<<endl<<
        address<<endl<<
        phone<<endl<<
        dob.toString()<<endl<<
        balance<<endl;
}