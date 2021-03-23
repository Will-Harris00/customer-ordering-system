#include "SalesOrder.hpp"
using namespace std;

SalesOrder::SalesOrder(string salesOrderRecord)
{
    if ( !containsOnlyNum(salesOrderRecord) )
        exit(-9);

    this->customerNum = atoi((salesOrderRecord.substr(10,4)).c_str());   // starting index ten, length four
    this->orderQuantity = atoi((salesOrderRecord.substr(14,3)).c_str()); // starting index fourteen, length three
    this->orderDate = atoi((salesOrderRecord.substr(1,8)).c_str());      // starting index one, length eight
    this->orderType = salesOrderRecord[9];
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
