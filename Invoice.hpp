#ifndef __INVOICE__
#define __INVOICE__ 1

#include <string>

#include "Customer.hpp"
using namespace std;

class Invoice: public Customer
{
        static unsigned int invoiceNum;
    public:
        Invoice(const Customer &b): Customer(b) {}; // inherit customer class with associated data
        void sendOrder();
};

#endif
