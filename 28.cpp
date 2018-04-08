#include <iostream>
using namespace std;


double fnDepositAmount(double = 500.0, int =10, double = 8.0);

int main(void)
{
    double dPrincipal, dAmount, dRate;
    int iYears;
    
    //cout << "\nEnter the principal rate and years" << endl;
    //cin >> dPrincipal >> dRate >> iYears;
    
    dAmount = fnDepositAmount(1000,20,5.0);
    
    cout << "\nAmount at the end of term is : " << dAmount << endl;
    
    dAmount = fnDepositAmount(1000,15);
    
    cout << "\nAmount at the end of term is : " << dAmount << endl;

    dAmount = fnDepositAmount(1000);
    
    cout << "\nAmount at the end of term is : " << dAmount << endl;

    dAmount = fnDepositAmount();
    return 0;
}

double fnDepositAmount(double dP, int iY, double dR)
{
    double dAm = dP;
    int iCount;
    for(iCount = 1; iCount <= iY; iCount++)
    {
        dAm = dAm * (1 + dR/100);
    }
    return dAm;
}







