#include "Virtual.hpp"

base::base(string newStr)
{
    this->str = newStr;
}

int derived::id{1000}; 

int main()
{
    base *b = new base("Hello");
    derived d = {*b};
    delete b;
    d.print();
    /*
    derived *d = new derived();
    base *b = d;
    delete b;
    */

    return 0;
}

void derived::print()
{
    cout << str << "\n" << endl;
    cout << id << endl;
}

string base::getString()
{
    return this->str;
}
