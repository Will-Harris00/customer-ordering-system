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
}

void generateInvoice(Customer *customer)
{
    Invoice invoice = {*customer}; // create derived class from customer with associated data
    invoice.sendOrder();
    customer->setOrderQuantity(0); // reset order quantity to zero
}
