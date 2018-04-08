#include <iostream>
#include <cmath>
using namespace std;
class FractionType
{
    private:
        int iNum, iDen;
        
    public:
        FractionType();
        ~FractionType();
        FractionType(int,int);
        FractionType(int);
        FractionType(FractionType&);
        void fnSetFraction(int, int);
        void fnSetFraction(int);
        void fnShowFraction();
        void fnReduceFraction();
        FractionType fnAddFraction(FractionType);
};

FractionType :: FractionType(FractionType &f)
{
    cout << "\nCopy constructor\n";
    iNum = f.iNum;
    iDen = f.iDen;
}


FractionType :: FractionType()
{
//    cout << "\nZero parameter constructor\n";
    iNum = 0;
    iDen = 1;
}


FractionType :: ~FractionType()
{
    cout << "\nDestructor invoked\n";
}

FractionType :: FractionType(int iVal1, int iVal2)
{
//    cout << "\nTwo parameter constructor\n";
    iNum = iVal1;
    iDen = iVal2;
}

FractionType :: FractionType(int iVal1)
{
//    cout << "\nOne parameter constructor\n";
    iNum = iVal1;
    iDen = 1;
}

void FractionType :: fnSetFraction(int iN, int iD)
{
    iNum = iN;
    iDen = iD;
}

void FractionType :: fnSetFraction(int iN)
{
    iNum = iN;
    iDen = 1;
}
    
void FractionType :: fnShowFraction()
{
    cout << "Fraction : " << "( " << iNum << " / " << iDen << " )" << endl;
}

FractionType FractionType :: fnAddFraction(FractionType b)
{
//    FractionType res;
    int iN, iD;
    iN = (iNum * b.iDen + iDen * b.iNum);
    iD = (iDen * b.iDen);
//    res.fnShowFraction();
//    return res;
	FractionType f(iN, iD);
	return f;
}

int main(void)
{
    FractionType f1,f2(5,6),f3;//,f5;    

//    f1.fnShowFraction();  
//    f2.fnShowFraction();
    
//    cout << "\nEnter the first fraction" << endl;
    f1.fnSetFraction(3);
    f2.fnSetFraction(1,4);  
    
    f1.fnShowFraction();  
    f2.fnShowFraction();
    f3 = f1.fnAddFraction(f2);
    f3.fnShowFraction();

//    FractionType f4(f3); 
//    f4.fnShowFraction();   
//    FractionType f5=f4;
//    f5.fnShowFraction();   
    
//    FractionType f4(2,5);    
//    f4.fnShowFraction();   
    return 0;
}


