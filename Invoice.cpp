#include "Invoice.hpp"
using namespace std;

unsigned int Invoice::invoiceNum{1000};

void Invoice::sendOrder()
{
    cout << "OP: customer " << setw(4) << setfill('0') << customerNum
         << ": shipped quantity " << quantityOrdered << endl;

    cout << "SC: customer " << setw(4) << setfill('0') << customerNum
         << ": date " << date
         << ": invoice " << invoiceNum++
         << ": quantity " << quantityOrdered << endl;
    this->quantityOrdered = 0; // reset customer order quantity
}
