// This program uses explicit scope resolution to select i.
#include <iostream>
using namespace std;
class base {
    public:
        int i;
};

// derived1 inherits base.
class derived1 : public base {
    public:
        int j;
};


// derived2 inherits base.

class derived2 : public base {
    public:
        int k;
};

/* derived3 inherits both derived1 and derived2.
This means that there are two copies of base
in derived3! */

class derived3 : public derived1, public derived2 {
    public:
        int sum;
};

int main()
{
    derived3 ob;
    ob.derived1::i = 10; // scope resolved, use derived1's i
    ob.derived2::i = ob.derived1::i * 2;
    ob.j = 20;
    ob.k = 30;
    // scope resolved
    ob.sum = ob.derived1::i + ob.j + ob.k;
    // also resolved here
    cout << ob.derived1::i << " ";
    cout << ob.derived2::i << " ";
    cout << ob.j << " " << ob.k << " ";
    cout << ob.sum << endl;
    return 0;
}

