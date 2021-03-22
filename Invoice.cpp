#include "Invoice.hpp"
using namespace std;

unsigned int Invoice::invoiceNum{1000}; // invoice numbers start at 1000 and are incremented by one each time

void Invoice::sendOrder()
{
    cout << "OP: customer " << setw(4) << setfill('0') << customerNum
         << ": shipped quantity " << quantityOrdered << endl;

    cout << "SC: customer " << setw(4) << setfill('0') << customerNum
         << ": invoice " << invoiceNum++
         << ": date " << date
         << ": quantity " << quantityOrdered << endl;
    this->quantityOrdered = 0; // reset customer order quantity
}
