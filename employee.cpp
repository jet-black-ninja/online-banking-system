#include "headers/employee.h"

#include <iostream>
using namespace std;
void Employee::showDetails() const{
    cout<<
    ID<<endl<<
    name<<endl<<
    address<<endl<<
    phone<<endl<<
    dob.toString()<<endl<<
    salary<<endl;

}
float Employee::getSalary() const{
    return this->salary;
}