#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<iostream>
#include "person.h"
#include "timestamp.h"
class Employee:public Person{
    private:
    float salary;
    public:
    Employee():Person(),salary(0){};
    Employee(int ID, const char* name , const char* address, long int phone ,TimeStamp dob, const char* pass, float salary):
    Person(ID, name, address, phone , dob , pass),salary(salary){}
    Employee(const Employee& other ):Person(other),salary(other.salary){}
    float getSalary()const;
    void showDetails()const;
};
#endif //EMPLOYEE_H