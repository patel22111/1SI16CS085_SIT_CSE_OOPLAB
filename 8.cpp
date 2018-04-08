#include <iostream>
using namespace std;

void swap(int&, int&);      //void swap(int*, int*);
int main()
{
    int iVal1, iVal2;
    
    iVal1 = 6;
    iVal2 = 8;
    cout << "\nBefore Swapping\n";
    cout << iVal1 << "\t";
    cout << iVal2 << endl;    
    
    swap(iVal1, iVal2); //    swap(&iVal1, &iVal2);
            
    cout << "\nAfter Swapping\n";
    cout << iVal1 << "\t";
    cout << iVal2 << endl;    
    
    return 0;
}    

void swap(int &m, int &n)   //void swap(int *m, int *n)
{
    int t;
    t = m;  m = n;  n = t;
}


