#ifndef __CUSTOMER__
#define __CUSTOMER__ 1

#include <iostream>
#include <string>
#include <iomanip> // std::setfill, std::setw

#include "SalesOrder.hpp"
using namespace std;

class Customer
{
    protected: // access needed by derived invoice class
        unsigned int customerNum;
        unsigned int quantityOrdered;
        unsigned int date;
        string customerName;
    public:
        Customer(string);
        unsigned int getCustomerNum();
        unsigned int getQuantityOrdered();
        void setDate(unsigned int);
        void setOrderQuantity(unsigned int);
        friend void addOrderQuantity(Customer&, SalesOrder*);
};

#endif
