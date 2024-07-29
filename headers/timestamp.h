#ifndef TIMESTAMP_H
#define TIMESTAMP_H

#include <iostream>
class TimeStamp{
    unsigned int date;
    unsigned int month;
    unsigned int year;

    int timeWeight() const;

    public :
    TimeStamp(): date(0),month(0),year(0){};
    TimeStamp(unsigned int date, unsigned int month, unsigned int year) :date(date), month(month), year(year) {};
    //return (year* 10000)+(month * 100)+(date*1)
    //copy constructor

    TimeStamp(const TimeStamp &other);
    void set (unsigned int , unsigned int , unsigned int);
    std::string toString() const ;
    bool operator>(const TimeStamp&) const;
    bool operator<(const TimeStamp&) const;
    bool operator==(const TimeStamp&) const;
};

#endif //TIMESTAMP_H