#include <iostream>
#include <iomanip>
using namespace std;
 
class Distance
{
	private:
		int feet;             // 0 to infinite
		int inches;           // 0 to 12
	public:
	// required constructors
		Distance(){
			feet = 0;
			inches = 0;
		}
		Distance(int f, int i){
			cout << "Constructor" << endl;
			feet = f;
			inches = i;
		}
      
		Distance operator+(int);
		Distance operator-(Distance);
		Distance operator=(Distance);
		Distance operator++();	//prefix version
		Distance operator++(int);	//postfix version
		bool operator==(Distance);
		Distance operator()(int, int);

//		friend Distance operator++(Distance&);	//prefix version
//		friend Distance operator++(Distance&, int);	//postfix version
		friend Distance operator+(Distance, Distance);
		friend ostream& operator<<( ostream&, const Distance& );
		friend istream& operator>>( istream&, Distance& );
};

//D1 + D2		operator+(D1,D2)
Distance operator+(Distance d1,Distance d2)
{
	cout << "Calling Friend Function" << endl;
    Distance d3;
    d3.inches = d1.inches + d2.inches;
    d3.feet = d1.feet + d2.feet;
    if(d3.inches >= 12)
        d3.feet++;
    d3.inches = d3.inches % 12;
    return d3;
}

Distance Distance :: operator+(int d)
{
    Distance d3;
    d3.feet = feet + d;
    d3.inches = inches;
    return d3;
}

//D1 - D2		D1.operator-(D2)
Distance Distance :: operator-(Distance d2)
{
    int iLen1, iLen2;
    iLen1 = feet * 12 + inches;
    iLen2 = d2.feet * 12 + d2.inches;

    if(iLen1 < iLen2)
    {
        cout << "Wrong Input" << endl;
    }
    else
    {
        Distance d3;
        d3.inches = (iLen1-iLen2)%12;
        d3.feet = (iLen1-iLen2)/12;
        return d3;
    }
}

Distance Distance :: operator=(Distance d2)
{
    inches = d2.inches;
    feet = d2.feet;
    return *this;
}

bool Distance :: operator==(Distance d2)
{
    if(inches == d2.inches && feet == d2.feet)
        return true;
    return false;
}
//++D1			D1.operator++()
Distance Distance :: operator++()
{
	feet++;
	return *this;
}

//D1++

Distance Distance :: operator++(int dummy)
{
	feet++;
	return *this;
}

//++D1    operator++(D1)
//friend approach prefix version
//Distance operator++(Distance &d)
//{
//	d.feet++;
//	return d;
//}

////friend approach postfix version
//Distance operator++(Distance &d, int dummy)
//{
//	d.feet++;
//	return d;
//}

//cout << D1   operator<<(cout, D1)
//cannot use member function approach first parameter is not of Distance Type
ostream& operator<<(ostream &output, const Distance &D)
{ 
    output << "F : " << setw(2) << D.feet << " --- " << "I : " << setw(2) << D.inches;
    return output;		//chaining
}

//     cin >> D3;               operator>>(cin, D3)

istream& operator>>(istream &input, Distance &D)
{ 
    input >> D.feet >> D.inches;
    return input;            
}

int main()
{
	Distance D1(11, 6), D2, D3, D4, D5;

	cout << "First Distance :\t" << D1 << endl;
	cout << "Enter the value of Second Distance object : " ;
	cin >> D2;

	D3 = D1 + D2;
	D4 = D1 - D2;

	cout << "First Distance :\t" << D1 << endl;
	cout << "Second Distance :\t" << D2 << endl;
	cout << "Sum Distance :\t\t" << D3 << endl;
	cout << "Diffference : \t\t" << D4 << endl;   

	cout << "First Distance :\t" << D1 << endl;
	++D1;
	cout << "Updated First Distance :\t" << D1 << endl;
	D1++;
	cout << "Updated First Distance :\t" << D1 << endl;
	return 0;
}

