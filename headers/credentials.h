#ifndef CREDENTIALS_H
#define CREDENTIALS_H

#include <iostream>
#include <cstring>
class Credential{
    public :
    int ID;
    char pass[30];
    Credential():ID(-1){
        strcpy(this->pass,"\0");
    }
    Credential(int ID , const char* pass):ID(ID){
        strcpy(this->pass, pass);
    }
    void setID(int ID);
    void setPass(const char* pass);
    bool operator==(const Credential&);
};

#endif //CREDENTIALS_H