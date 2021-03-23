#include "SalesOrder.hpp"

using namespace std;

SalesOrder::SalesOrder(string salesOrderRecord)
{
    if ( !containsOnlyNum(salesOrderRecord) )
        exit(-10);

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

bool containsOnlyNum(string salesOrderRecord)
{
    // tail of sales order record from index ten onwards should contain seven integer digits
    int posNonInt = (salesOrderRecord.substr(10)).find_first_not_of( "0123456789" ); // position of first non-integer character
    if ( posNonInt == string::npos ) // tail contains integer values only
        return true;
    else if ( 0 <= posNonInt && posNonInt <= 3 ) // customer number is invalid
    {
        cerr << "Invalid customer identifier '" << salesOrderRecord << "'" << endl;
        return false;
    }
    else if ( 4 <= posNonInt && posNonInt <= 6 ) // order quantity is invalid
    {
        cerr << "Invalid order quantity '" << salesOrderRecord << "'" << endl;
        return false;
    }
}
