#include "ProcessRecord.hpp"
using namespace std;

void processLine(string line)
{   
    static vector<Customer *> customers; // customers are stored for use outside the scope of this function

    processRecord(line, customers);
}

void processRecord(string line, vector<Customer *> &customers)
{
    char recordType = line[0];
    if ( recordType == REC_END_OF_DAY )
    {
        extractDate(line); // checks date formatting and validation
        processEndOfDay(line, customers);
    }
    else if ( recordType == REC_NEW_CUSTOMER )
    {
        processNewCustomer(line, customers);
    }
    else if ( recordType == REC_SALES_ORDER )
    {
        extractDate(line); // checks date formatting and validation
        processSalesOrder(line, customers);
    }
    else
    {
        cerr << "Invalid record format. Record: " << line << endl;
        exit(-3);
    }
}

void processNewCustomer(string newCustomerRecord, vector<Customer *> &customers)
{
    if ( newCustomerRecord.length() > 47 ) // check length of new customer record matches specification
    {
        cerr << "New customer formatting is incorrect. Record: " << newCustomerRecord << endl;
        exit(-4);
    }

    Customer *newCustomer = new Customer(newCustomerRecord);
    customers.push_back(newCustomer);
    // fill up to four spaces with zero values
    cout << "OP: customer " << setw(4) << setfill('0') << newCustomer->getCustomerNum() << " added" << endl;
}

void processSalesOrder(string salesOrderRecord, vector<Customer *> &customers)
{
    if ( salesOrderRecord.length() != 17 ) // check length of sales order record matches specification
    {
        cerr << "Sales order formatting is incorrect. Record: " << salesOrderRecord << endl;
        exit(-5);
    }

    SalesOrder *newOrder = new SalesOrder(salesOrderRecord);
    if ( !addCustomerOrder(newOrder, customers) )
    {
        cerr << "Sales order could not be processed. Record: " << salesOrderRecord << endl;
        exit(-6);
    }

    // free memory allocated to latest order
    delete newOrder;
}

void processEndOfDay(string endOfDayRecord, vector<Customer *> &customers)
{
    if ( endOfDayRecord.length() != 9 ) // check length of end of day record matches specification
    {
        cerr << "End of day formatting is incorrect. Record: " << endOfDayRecord << endl;
        exit(-7);
    }

    cout << "OP: end of day " << endOfDayRecord.substr(1) << endl; // end of day date stamp
    for (Customer *customer : customers)
    {
        if ( customer->getQuantityOrdered() > 0 )
        {
            generateInvoice(customer);
        }
    }
}

bool addCustomerOrder(SalesOrder *newOrder, vector<Customer *> &customers)
{
    bool isExpress = false;
    bool existsCustomer = false;
    for (Customer *customer : customers)
    {
        if ( newOrder->getCustomerNum() == customer->getCustomerNum() )
        {
            existsCustomer = true;
            customer->setDate(newOrder->getOrderDate());

            unsigned int newQuantity = newOrder->getOrderQuantity() + customer->getQuantityOrdered();
            customer->setOrderQuantity(newQuantity); // increase customer order quantity according to new order

            string orderType;
            if ( newOrder->getOrderType() == ORD_NORMAL )
            {
                orderType = "normal";
            }
            else if ( newOrder->getOrderType() == ORD_EXPRESS )
            {
                orderType = "EXPRESS";
                isExpress = true;
            }
            else
            {
                cerr << "Order type identifier '" << newOrder->getOrderType() << "' is invalid." << endl;
                return false;
            }
            cout << "OP: customer " << setw(4) << setfill('0') << newOrder->getCustomerNum() 
                 << ": " << orderType << " order: quantity " << newOrder->getOrderQuantity() << endl;
            
            if ( isExpress )
                generateInvoice(customer);
            return true;
        }
    }

    if ( !existsCustomer ) // false if order does not belong to existing customer
        cerr << "Customer number '" << newOrder->getCustomerNum() << "'" << " does not exist." << endl;
    return false;
}
