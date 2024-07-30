#ifndef TXN_H
#define TXN_H

#include "timestamp.h"
#include "customer.h"
#include "support.h"

class Txn{
    int id ;
    TimeStamp ts;
    Customer cust;
    float amount;
    char type;
    public :
    Txn(int id , TimeStamp ts, Customer cust , float amount,char type ):id(id),ts(ts),cust(cust),amount(amount),type(type){}
    void printTxn() const;
};
#endif //TXN_H