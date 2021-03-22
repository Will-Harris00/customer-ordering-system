#include "ProcessRecord.hpp"
using namespace std;

void processLine(string line)
{   
    vector<Customer *> customers;

    processRecord(line, customers);
}

bool processRecord(string line, vector<Customer *> &customers)
{
    char recordType = line[0];
    if ( recordType == REC_END_OF_DAY )
    {
        extractDate(line); // checks date formatting and validation
        processEndOfDay(line);
        return true;
    }
    else if ( recordType == REC_NEW_CUSTOMER )
    {
        processNewCustomer(line, customers);
    }
    else if ( recordType == REC_SALES_ORDER )
    {
        extractDate(line); // checks date formatting and validation
        processSalesOrder(line);
    }
    else
    {
        cerr << "Invalid record format. Record: " << line << endl;
        exit(-3);
    }
    return false;
}

void processNewCustomer(string line, vector<Customer *> &customers)
{
    Customer *newCustomer = new Customer(line);
    customers.push_back(newCustomer);
    // fill up to four spaces with zero values
    cout << "OP: customer " << setw(4) << setfill('0') << newCustomer->getCustomerNum() << " added" << endl;
}

void processSalesOrder(string line)
{
    cout << line << endl;
}

void processEndOfDay(string line)
{
    cout << line << endl;
}

void extractDate(string line)
{
    unsigned int year = atoi(line.substr(1,4).c_str());  // starting index one, length four
    unsigned int month = atoi(line.substr(5,2).c_str()); // starting index five, length two
    unsigned int day = atoi(line.substr(7,2).c_str());   // starting index seven, length two
    
    if ( validateDate(year, month, day) )
        exit(-4);
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
