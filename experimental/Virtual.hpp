#ifndef __VIRTUAL__
#define __VIRTUAL__ 1

#include <iostream>
#include <string>
using namespace std;

class base {
    protected:
        string str;
    public:
        base(string);
        virtual ~base() {};
        string getString();
};

class derived: public base {
        static int id;
    public:
        derived(base &thisBase): base(thisBase) {};
        ~derived() {};
        void print();
};

#endif
