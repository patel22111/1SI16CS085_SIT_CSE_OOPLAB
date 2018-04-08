#include <iostream>
using namespace std;

int main()
{
    int iVal;
    int &refVal = iVal;
    
    iVal = 6;
    cout << iVal << endl;
    cout << refVal << endl;    
    
    refVal++;
    cout << iVal << endl;
    cout << refVal << endl;    
        
    return 0;
}    
