#include "Customer.hpp"
using namespace std;

Customer::Customer(string newCustomerRecord)
{
    this->customerNum = stoi((newCustomerRecord.substr(1,4))); // starting index one, length four
    this->customerName = newCustomerRecord.substr(5,39);       // starting index five, length 39
    this->quantityOrdered = 0;
    this->date = 0;
}

unsigned int Customer::getCustomerNum()
{
    return this->customerNum;
}

unsigned int Customer::getQuantityOrdered()
{
    return this->quantityOrdered;
}

void Customer::setDate(unsigned int date)
{
    this->date = date;
}

void Customer::setOrderQuantity(unsigned int quantityOrdered)
{
    this->quantityOrdered = quantityOrdered;
}
