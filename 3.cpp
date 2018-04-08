#include <iostream>
using namespace std;

int m = 10;
int main()
{
    int m = 20;
    {
        int k = m;
        m = 30;
        
        cout << "Inner Block\n";
        cout << "k = " << k << "\n";
        cout << "m = " << m << "\n";        
        cout << "::m = " << ::m << "\n";                
    }
    cout << "Outer Block\n";
    cout << "m = " << m << "\n";        
    cout << "::m = " << ::m << "\n";        
    return 0;
}
