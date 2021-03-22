#ifndef __CUSTOMER__
#define __CUSTOMER__ 1

#include <iostream>
#include <string>
#include <iomanip> // std::setfill, std::setw

using namespace std;

class Customer
{
        unsigned int customerNum;
        unsigned int quantityOrdered;
        unsigned int date;
        string customerName;
    public:
        Customer(string);
        unsigned int getCustomerNum();
        unsigned int getQuantityOrdered();
        void setDate(unsigned int);
};

#endif
