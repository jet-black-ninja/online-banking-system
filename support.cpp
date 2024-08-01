#include "headers/support.h"

void Support::delay() const{
//TODO add default delay
}

void Support::delay(const long int) const {
    //TODO add delay with input value
}

void Support::drawLine(int n = 50)const{
    for(int i = 0; i<n;i++){
        std::cout<<"-";
    }
    std::cout<<std::endl;
}
void Support::drawLine(const char ch, int n=50) const {
    
    for(int i = 0;i<n;i++){
        std::cout<<ch;
    }
    std::cout<<std::endl;
}

void Support::drawLineTrans(int n = 50, int ms = 50)const{
    for(int i = 0; i<n;i++){
        std::cout<<"-";
        delay(ms);
    }
    std::cout<<std::endl;
}

void Support::transText(const std::string str, int ms) const{
    delay(ms);
    std::cout<<str<<std::endl;
}