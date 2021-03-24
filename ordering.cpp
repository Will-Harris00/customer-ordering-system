#include "ordering.hpp"
using namespace std;

/*****************************************************************************/
/* Usage: ./ordering <input-file-name>                                       */
/*****************************************************************************/
int main (int argc, char **argv)
{
    if ( argc != 2 )
    {
        cerr << "Invalid number of arguments - Two parameters are required to run the program." << endl;
        exit(-1);
    }

    string filename = argv[1];

    vector<Customer *> customers; // vectors of customer objects

    readFile(filename, customers);

    for (Customer *customer : customers)
        delete customer;

    return 0;
}
