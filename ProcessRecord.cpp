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

    string date = endOfDayRecord.substr(1);
    cout << "OP: end of day " << date << endl;
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
    for (Customer *customer : customers)
    {
        if ( newOrder->getCustomerNum() == customer->getCustomerNum() )
        {
            customer->setDate(newOrder->getOrderDate());
            // Increase quantity ordered for respective customer
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
                exit(-8);
            }
            cout << "OP: customer " << setw(4) << setfill('0') << newOrder->getCustomerNum() 
                 << ": " << orderType << " order: quantity " << newOrder->getOrderQuantity() << endl;
            
            if ( isExpress )
                generateInvoice(customer);
            return true;
        }
    }
    return false;
}

void extractDate(string line)
{
    unsigned int year = atoi(line.substr(1,4).c_str());  // starting index one, length four
    unsigned int month = atoi(line.substr(5,2).c_str()); // starting index five, length two
    unsigned int day = atoi(line.substr(7,2).c_str());   // starting index seven, length two
    
    if ( validateDate(year, month, day) )
        exit(-9);
}

int validateDate(unsigned int year, unsigned int month, unsigned int day)
{
    switch (month)
    {    
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if ( day > 31 )
            {
                cerr << "Invalid date - more than 31 days '" << day << "' in month '" << month << "'. Date: " << year << month << day << endl;
                return 1;
            }
            else 
                return 0;
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            if (day > 30)
            {
                cerr << "Invalid date - more than 30 days '" << day << "' in month '" << month << "'. Date: " << year << month << day << endl;
                return 1;
            }
            else 
                return 0;
            break;

        case 2:
            if (year % 4 == 0) // leap year
            {
                if (day > 29)
                {
                    cerr << "Invalid date - February has more than 29 days '" << day << "' in a leap year '" << year << "'. Date: " << year << month << day << endl;
                    return 1;
                }
                else
                    return 0;
            }
            else
                if (day > 28)
                {
                    cerr << "Invalid date - February has more than 28 days '" << day << "' in a non-leap year '" << year << "'. Date: " << year << month << day << endl;
                    return 1;
                }
                else
                    return 0;
            break;

        default:
            cerr << "Invalid month - month '" << month << "' does not exist. Date: " << year << month << day << endl;
            return 1;
    }
}
