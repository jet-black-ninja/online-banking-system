#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include "customer.h"

class Controller{
static bool sortCustomerByName (const Customer&, const Customer&);
static bool sortCustomerByDob(const Customer& , const Customer&);
static bool sortCustomerById(const Customer&, const Customer&);
static bool sortCustomerByBalance(const Customer&, const Customer&);

public:
static void showBanner();
static void showMenu();
static void shoeCustomerLogin();
static void showCustomerPortal(const int SESSION);
static void showEmployeeLogin();
static void showEmployeePortal(const int SESSION);
static void showAdmin();
static void showCredits();
static void addCustomer();
static void modifyCustomer();
static void displayCustomer();
static void deleteCustomer();
static void displayCustomerBy();
static void addEmployee();
static void modifyEmployee();
static void displayEmployee();
static void deleteEmployee();
static void deposit();
static void withdraw();
static void changeCustomerPassword(const int SESSION);
};

#endif //CONTROLLER_H
