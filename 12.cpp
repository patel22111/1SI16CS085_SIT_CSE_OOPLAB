#include <iostream>
using namespace std;

void fnSumDiff(int, int, int&, int&);
int main()
{
    int iVal1, iVal2, iSum, iDiff;
    
    cout << "\nEnter two values\n";
    cin >> iVal1 >> iVal2;
    
    fnSumDiff(iVal1, iVal2, iSum, iDiff);
    
    cout << "\nSum is : " << iSum;
    cout << "\nDifference is : " << iDiff;
    
    return 0;
}

void fnSumDiff(int iM, int iN, int &iS, int &iD)
{
    iS = iM + iN;
    iD = iM - iN;
}


