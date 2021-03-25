#include "VirtualVector.hpp"

base::base(string newStr)
{
    this->str = newStr;
}

int derived::id{1000}; 

int main()
{
    vector<base *> basevec;
    for (int i = 0; i < 3; i++)
    {
        base *b = new base("Hello");
        basevec.push_back(b);
    }
    base *b = new base("Hello");
    derived d = {*b};
    delete b;
    d.print();
    /*
    derived *d = new derived();
    base *b = d;
    delete b;
    */
    for (base *b : basevec)
    {
        /*delete &(*b); */
        delete *(&b);
        // delete b;
    }
    
    /*
    for ( size_t vecSize = 0; vecSize < basevec.size(); vecSize++)
        delete basevec[vecSize];
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
