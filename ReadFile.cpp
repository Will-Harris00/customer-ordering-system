#include "ReadFile.hpp"
using namespace std;

void readFile(string filename, vector<Customer *> customers)
{
    ifstream inputFile(filename);
    // exit the program if input stream not created.
    if (!inputFile)
    {
        cerr << "File not openable." << endl;
        exit(-2);
    }

    // temp variable for storing current line in file
    string line;
    while (getline(inputFile, line))
    {
        // process current line
        processRecord(line, customers);
    }

    inputFile.close();
}
