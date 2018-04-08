	#include <iostream>
	using namespace std;
	class FractionType
	{
		private:
		    int iNum, iDen;
		    //int *ptr;
		    
		public:
			FractionType(){}
		    FractionType(int,int);

		    void fnSetFraction(int, int);
		    void fnShowFraction();

			//binary operators
			FractionType operator+(FractionType);//f1+f2 --> f1.operator+(f2)
			FractionType operator+(int);			//f1.operator(int)
			FractionType operator-(FractionType);
			FractionType operator*(FractionType);
			bool operator==(FractionType);
			FractionType operator=(FractionType);
		
		
			//unary operator
			FractionType operator-(void);	// -f2	--> f2.operator-()	
			FractionType operator++(void);	// ++f3 --> f3.operator++()
			FractionType operator--(void);
			FractionType operator++(int);		//	postfix version
	};

	//unary version
	FractionType FractionType :: operator-(void)
	{
		FractionType temp;
		temp.iNum = -iNum;
		temp.iDen = iDen;
		return temp;
	}
	// p = q			p.operator=(q)
	FractionType FractionType :: operator=(FractionType f2)
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
	FractionType FractionType :: operator++(void)
	{
		cout << "\nPrefix version" << endl;
		iNum = iNum + iDen;
		return *this;
	}
	
	//postfix version
	FractionType FractionType :: operator++(int dummy)
	{
		cout << "\nPostfix version" << endl;
		FractionType old(*this);
		iNum = iNum + iDen;
		return old;
	}

	FractionType FractionType :: operator--(void)
	{
		iNum = iNum - iDen;
		return *this;
	}

	FractionType FractionType :: operator+(int val)	//f3+5	f3.operator+(5)
	{
		FractionType f3;
		f3.iNum = iNum + iDen * val;
		f3.iDen = iDen;
		return f3;
	}


	bool FractionType :: operator==(FractionType f2)
	{
		if(iNum * f2.iDen == iDen * f2.iNum)
			return true;
		else
			return false;
	}

	FractionType FractionType :: operator*(FractionType f2)
	{
		FractionType f3;
		f3.iNum = iNum * f2.iNum;
		f3.iDen = iDen * f2.iDen;
		return f3;
	}


	FractionType FractionType :: operator-(FractionType f2)
	{
		FractionType f3;
		f3.iNum = iNum * f2.iDen - iDen * f2.iNum;
		f3.iDen = iDen * f2.iDen;
		return f3;
	}


	FractionType FractionType :: operator+(FractionType f2)
	{
		FractionType f3;
		f3.iNum = iNum * f2.iDen + iDen * f2.iNum;
		f3.iDen = iDen * f2.iDen;
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
	
	
		++a;
		a++;
	
		// f3 = f1.fnAddFraction(f2);
	//	r = p + q;			//p.operator+(q)
	//	
	//	p.fnShowFraction();

	//	r = q + 2;
	//	q.fnShowFraction();
	//	r.fnShowFraction();
	
	//	r = 5 + q;		//doesnt work

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
		cout << "****CASE 1****\n";
		cout << "p : ";
		p.fnShowFraction();
		q = ++p;
		cout << "q : ";
		q.fnShowFraction();
		cout << "p : ";
		p.fnShowFraction();

		cout << "****CASE 2****\n";
		p.fnSetFraction(3,4);
		cout << "p : ";
		p.fnShowFraction();
		q = p++;
		cout << "q : ";		
		q.fnShowFraction();
		cout << "p : ";
		p.fnShowFraction();
		
		return 0;	
	}

























