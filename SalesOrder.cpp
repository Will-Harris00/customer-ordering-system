#include "SalesOrder.hpp"
using namespace std;

SalesOrder::SalesOrder(string salesOrderRecord)
{
    if ( !containsOnlyNum(salesOrderRecord) )
        exit(EXIT_FAILURE);

    this->customerNum = stoi((salesOrderRecord.substr(10,4)));   // starting index ten, length four
    this->orderQuantity = stoi((salesOrderRecord.substr(14,3))); // starting index fourteen, length three
    this->orderDate = stoi((salesOrderRecord.substr(1,8)));      // starting index one, length eight
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
