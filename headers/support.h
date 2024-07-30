#ifndef SUPPORT_H
#define SUPPORT_H

#include <iostream>
class Support{
    public:
    void delay() const;
    void delay(const long int) const;
    void drawLine(int) const;
    void drawLine(const char, int) const ;
    void drawLineTrans(int , int)const ;
    void drawLineTrans(const char,int ,int) const;
    void transText(const std:: string, int) const;  
};

#endif //SUPPORT_h