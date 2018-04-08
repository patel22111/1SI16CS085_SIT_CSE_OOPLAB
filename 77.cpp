#include <iostream>
using namespace std;
class FractionType
{
	private:
	    int iNum, iDen;
	    
	public:
		FractionType(){}
	    FractionType(int,int);

	    void fnSetFraction(int, int);
	    void fnShowFraction();

		//binary operators
		friend FractionType operator+ (const FractionType&, const FractionType&);
		//f1+f2 --> operator+(f1,f2)
		
		friend FractionType operator+(const FractionType&,int);			
		//f1+6  --> operator(f1,6)
		friend FractionType operator+(int, const FractionType&);			
		//7+f3  --> operator(7,f3)
		friend bool operator==(const FractionType& , const FractionType&);
		FractionType operator=(const FractionType&);		//cannot use friend approach
	
	
//		//unary operator
		friend FractionType operator-(FractionType&);	
//		// -f2	--> operator-(f2)	
//		friend FractionType operator++(FractionType&);	
//		// ++f3 --> operator++(f3)
//	/*	FractionType operator--(void);*/
//		friend FractionType operator++(const FractionType&, int);		
//		//	postfix version  f4++  --> operator++(f4, int)
		
		friend ostream& operator<<(ostream&, const FractionType&);
};
//cout << p;		operator<<(cout, p)
ostream& operator<<(ostream &out, const FractionType &f)
{
	out << "Fraction : " << "( " << f.iNum << " / " << f.iDen << " )" << endl;
	return out;
}

//unary version
FractionType operator-(FractionType &f1)
{
	f1.iNum = -1 * f1.iNum;
}

// p = q			p.operator=(q)
FractionType FractionType :: operator=(const FractionType &f2)
{
	iNum = f2.iNum;
	iDen = f2.iDen;
	return *this;
}

//	p = q = r;		p =	q.operator=(r)

//FractionType FractionType :: operator++(void)
//{
//	FractionType temp;
//	temp.iNum = iNum + iDen;
//	temp.iDen = iDen;
//	return temp;
//}



//prefix version
//FractionType operator++(FractionType &f1)
//{
//	cout << "\nPrefix version" << endl;
//	f1.iNum = f1.iNum + f1.iDen;

//}

////postfix version
//FractionType operator++(FractionType &f1, int dummy)
//{
//	cout << "\nPostfix version" << endl;
//	f1.iNum = f1.iNum + f1.iDen;
//}

//	FractionType FractionType :: operator--(void)
//	{
//		iNum = iNum - iDen;
//		return *this;
//	}

//f3+5	operator+(f3, 5);
FractionType operator+(const FractionType &f1, int val)
{
	FractionType f3;
	f3.iNum = f1.iNum + f1.iDen * val;
	f3.iDen = f1.iDen;
	return f3;
}

//7+f2		operator+(7, f2)
FractionType operator+( int val, const FractionType &f1)
{
	FractionType f3;
	f3.iNum = f1.iNum + f1.iDen * val;
	f3.iDen = f1.iDen;
	return f3;
}

bool operator==(const FractionType &f1, const FractionType &f2)
{
	if(f1.iNum * f2.iDen == f1.iDen * f2.iNum)
		return true;
	else
		return false;
}

//	FractionType FractionType :: operator*(FractionType f2)
//	{
//		FractionType f3;
//		f3.iNum = iNum * f2.iNum;
//		f3.iDen = iDen * f2.iDen;
//		return f3;
//	}


//	FractionType FractionType :: operator-(FractionType f2)
//	{
//		FractionType f3;
//		f3.iNum = iNum * f2.iDen - iDen * f2.iNum;
//		f3.iDen = iDen * f2.iDen;
//		return f3;
//	}

//p+q			operator+(p,q))
FractionType operator+(const FractionType &f1, const FractionType &f2)
{
	FractionType f3;
	f3.iNum = f1.iNum * f2.iDen + f1.iDen * f2.iNum;
	f3.iDen = f1.iDen * f2.iDen;
	return f3;
}


FractionType :: FractionType(int iVal1, int iVal2)
{
//    cout << "\nTwo parameter constructor\n";
	iNum = iVal1;
	iDen = iVal2;
}

void FractionType :: fnSetFraction(int iN, int iD)
{
	iNum = iN;
	iDen = iD;
}

void FractionType :: fnShowFraction()
{
	cout << "Fraction : " << "( " << iNum << " / " << iDen << " )" << endl;
}


int main()
{
	int a = 2, b = 7, c;

	FractionType p(3,4), q(1,3);
	FractionType r;

//		cout << p;
	
	//p + q;

//		++a;
//		a++;

	// f3 = f1.fnAddFraction(f2);
	r = p + q;			//operator+(p,q)
	
	cout << p;
	cout << q;
	cout << r;
//	
//	p.fnShowFraction();

	r = q + 2;
	cout << q;
	cout << r;

//	q.fnShowFraction();
//	r.fnShowFraction();

	r = 5 + q;		//doesnt work
	cout << q;
	cout << r;

	-r;
	cout << r;
//	if(p==q)			//p.operator==(q)
//		cout << "Fractions are equal" << endl;
//	else
//		cout << "Fractions are not equal" << endl;

//	r = -p;			// p.operator-()
//	p.fnShowFraction();
//	r.fnShowFraction();

//		q.fnShowFraction();
//		//r = ++q
//		r = --q;			// q.operator++()
//		q.fnShowFraction();
//		r.fnShowFraction();
//	cout << p;
//	++p;
//	cout << p;

//	cout << q;
//	q = p;
//	cout << q;
	
	
	
	
	return 0;	

}

























