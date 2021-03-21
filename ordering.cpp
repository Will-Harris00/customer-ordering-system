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

    readFile(filename);

    return 0;
}
