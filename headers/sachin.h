#ifndef SACHIN_H
#define SACHIN_H

#include <iostream>
class Sachin{
    public:
    void delay() const;
    void delay(const long int) const;
    void drawLine(int) const;
    void drawLine(const char, int) const ;
    void drawLineTrans(int , int)const ;
    void drawLineTrans(const char,int ,int) const;
    void transText(const std:: string, int) const;  
};

#endif //SACHIN_h