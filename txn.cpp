#include "headers/txn.h"
#include <iomanip>//for monetary value
#include <iostream>

void Txn::printTxn() const{
    Support support;
    support.drawLine(30);
    std::cout<<"\t\e[3mMINI-STATEMENT\e[0m"<<std::endl;
    support.drawLine(30);
    std::cout<<std::setw(20)<<"ID : "<<this->id<<std::endl
    <<std::setw(20)<<"Name : "<<(this->cust).getName()<<std::endl
    <<std::setw(20)<<"Txn Date : "<<(this->ts).toString()<<std::endl
    <<std::setw(20)<<"Amount : "<<(this->amount)<<std::endl
    <<std::setw(20)<<"Transaction type: "<<((type=='d'||type=='D')?"Debit":"Credit")<<std::endl;
    support.drawLine(30);
    std::cout<<"Have a nice day ..."<<std::endl;
    support.drawLine(30);
}

