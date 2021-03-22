#include "SalesOrder.hpp"

using namespace std;

SalesOrder::SalesOrder(string orderRecord)
{
    if ( orderRecord.length() != 17 ) // check length of string
    {
        cerr << "Sales order formatting is incorrect. Record: " << orderRecord << endl;
        exit(-6);
    }
    this->customerNum = atoi((orderRecord.substr(10,4)).c_str());   // starting index ten, length four
    this->orderQuantity = atoi((orderRecord.substr(14,3)).c_str()); // starting index fourteen, length three
    this->orderDate = atoi((orderRecord.substr(1,8)).c_str());      // starting index one, length eight
    this->orderType = orderRecord[9];
}

unsigned int SalesOrder::getCustomerNum()
{
    return this->customerNum;
}

unsigned int SalesOrder::getOrderQuantity()
{
    return this->orderQuantity;
}

unsigned int SalesOrder::getOrderDate()
{
    return this->orderDate;
}

char SalesOrder::getOrderType()
{
    return this->orderType;
}
