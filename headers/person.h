#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include "timestamp.h"
#include <cstring>

class Person{
    protected:
    int ID;
    //std::string name ;
    //std::string address
    char name[30];
    char address[30];
    long int phone;
    TimeStamp dob;
    //std::string pass;
    char pass[30];

    public:
    Person(){}
    Person(int ID, const char* name , const char * address, long int phone, TimeStamp dob, const char* pass):
        ID(ID),phone(phone),dob(dob){
            strcpy(this->name ,name);
            strcpy(this->address, address);
            strcpy(this->pass,pass);
        };
        Person(const Person&);

        virtual void showDetails() const=0;

        //making this class and abstract class
        //getters
        int getID() const;
        const char * getName() const;
        const char * getAddress() const;
        long int getPhone() const;
        TimeStamp getDob() const;
        const char* getPass() const;

        //setter
        void setPass(const char*);
};


#endif //PERSON_H