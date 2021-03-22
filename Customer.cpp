#include "Customer.hpp"
using namespace std;

Customer::Customer(string newCustomerRecord)
{
    this->customerNum = atoi((newCustomerRecord.substr(1,4)).c_str()); // starting index one, length four
    this->customerName = newCustomerRecord.substr(5,string::npos);     // starting index five
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

void addOrderQuantity(Customer &customer, SalesOrder *order)
{
    customer.quantityOrdered += order->getOrderQuantity();
}

void Customer::sendOrder()
{
    cout << "OP: customer " << setw(4) << setfill('0') << customerNum
         << ": shipped quantity " << quantityOrdered << endl;

    cout << "SC: customer " << setw(4) << setfill('0') << customerNum
         << ": date " << date
         << ": quantity " << quantityOrdered << endl;
    this->quantityOrdered = 0; // reset customer order quantity
}
