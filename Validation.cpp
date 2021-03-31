#include "Invoice.hpp"
using namespace std;

bool containsOnlyNum(string salesOrderRecord)
{
    // tail of sales order record from index ten onwards should contain seven integer digits
    int posNonInt = (salesOrderRecord.substr(10)).find_first_not_of( "0123456789" ); // position of first non-integer character
    if ( posNonInt == string::npos ) // tail contains integer values only
        return true;

    else if ( 0 <= posNonInt && posNonInt <= 3 ) // customer number is invalid
        cerr << "Invalid customer identifier '" << salesOrderRecord << "'" << endl;
    else if ( 4 <= posNonInt && posNonInt <= 6 ) // order quantity is invalid
        cerr << "Invalid order quantity '" << salesOrderRecord << "'" << endl;

    return false;
}

void extractDate(string line)
{
    unsigned int year = stoi(line.substr(1,4));  // starting index one, length four
    unsigned int month = stoi(line.substr(5,2)); // starting index five, length two
    unsigned int day = stoi(line.substr(7,2));   // starting index seven, length two
    
    if ( validateDate(year, month, day) )
        exit(EXIT_FAILURE);
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
