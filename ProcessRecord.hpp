#ifndef __PROCESSRECORD__
#define __PROCESSRECORD__ 1

#include <iostream>
#include <string>
#include <vector>

#include "Customer.hpp"
using namespace std;

#define ORD_NORMAL  'N'
#define ORD_EXPRESS 'X'

#define REC_NEW_CUSTOMER 'C'
#define REC_SALES_ORDER  'S'
#define REC_END_OF_DAY   'E'

/*----- function prototypes --------------------------------------------------*/

void processLine(string);
void processRecord(string, vector<Customer *> &);
void processNewCustomer(string, vector<Customer *> &);
void processSalesOrder(string, vector<Customer *> &);
void processEndOfDay(string, vector<Customer *> &);
bool addCustomerOrder(SalesOrder *, vector<Customer *> &);
void generateInvoice(Customer *);

#endif
