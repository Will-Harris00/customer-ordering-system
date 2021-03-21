#ifndef __PROCESSRECORD__
#define __PROCESSRECORD__ 1

#include <iostream>
#include <string>

using namespace std;

#define ORD_NORMAL  'N'
#define ORD_EXPRESS 'X'

#define REC_NEW_CUSTOMER 'C'
#define REC_SALES_ORDER  'S'
#define REC_END_OF_DAY   'E'

/*----- function prototypes --------------------------------------------------*/

void processRecord(string line);
void processNewCustomer(string line);
void processSalesOrder(string line);
void processEndOfDay(string line);
void extractDate(string line);
int validateDate(unsigned int, unsigned int, unsigned int);

#endif