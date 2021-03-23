#ifndef __SALESORDER__
#define __SALESORDER__ 1

#include <iostream>
#include <string>

#include "Validation.hpp"
using namespace std;

class SalesOrder
{
        unsigned int customerNum;
        unsigned int orderQuantity;
        unsigned int orderDate;
        char orderType;
    public:
        SalesOrder(string);
        unsigned int getCustomerNum();
        unsigned int getOrderQuantity();
        unsigned int getOrderDate();
        char getOrderType();
};

#endif
