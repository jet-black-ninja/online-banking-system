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

};

#endif //CONTROLLER_H
