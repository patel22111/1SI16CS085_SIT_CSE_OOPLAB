#include <iostream>
#include <iomanip>
using namespace std;

class DurationType
{
    int iHr, iMn, iSc;
    public:
    DurationType();
    DurationType(int);		//conversion constructor
    DurationType(int, int, int);
    DurationType operator+(const DurationType&);
    void operator=(int);
    operator int() const;	//conversion operator
    friend ostream& operator<<(ostream&, const DurationType&);
    friend istream& operator>>(istream&, DurationType&);
};

DurationType :: DurationType(int seconds)
{
    iMn = seconds / 60;
    iSc = seconds % 60;
    iHr = iMn / 60;
    iMn = iMn % 60;
    cout << "\nOne arg Constructor\n";
    cout << "Basic to Class type Conversion" << endl;    
}

DurationType :: operator int() const
{
	cout << "Class to Basic Type Conversion" << endl;
	return (iHr*60*60+iMn*60+iSc);
}

void DurationType :: operator=(int seconds)
{
    iMn = seconds / 60;
    iSc = seconds % 60;
    iHr = iMn / 60;
    iMn = iMn % 60;
    cout << "\nOverloaded Assignment\n";
    cout << "Basic to Class type Conversion" << endl;    
}

DurationType :: DurationType()
{
    iHr = iMn = iSc = 0;
}

DurationType :: DurationType(int h, int m, int s)
{
    iHr = h;
    iMn = m;
    iSc = s;
}

istream& operator>>(istream &in, DurationType &t)
{
    int h,m,s;
    cout << "\nEnter the duration : ";
    in >> h >> m >> s;
    if(m<60 && s<60)
    {
        t.iHr = h;
        t.iMn = m;
        t.iSc = s;
    }
    else
        cout << "\nInvalid Input\n";
    return in;
}

ostream& operator<<(ostream &out, const DurationType &t)
{
	out << setw(2) << setfill('0') << t.iHr << ":";
    out << setw(2) << setfill('0') << t.iMn << ":";
    out << setw(2) << setfill('0') << t.iSc << endl;
    return out;
}

DurationType DurationType :: operator+(const DurationType &d2)
{
    DurationType d3;
    int hh, mm, ss;
    ss = iSc + d2.iSc;
    mm = iMn + d2.iMn + (ss/60);
    hh = iHr + d2.iHr + (mm/60);
        
    d3.iSc = ss % 60;
    d3.iMn = mm % 60;
    d3.iHr = hh;
    return d3;
}

int main()
{
    DurationType d1,d3;
    DurationType d2(20000);	//basic to class type using constructor
    int timeInSec;
	cin.get();
	
	d1 = 10000;			//basic to class type using overloaded =
	cin.get();
	
    d3 = d1 + d2;      
    timeInSec = static_cast<int>d3;		//class to basic type
    //The type parameter must be a data type to which object can be converted via a known method
    
	cin.get();    
    cout << "\nDuration 1 : ";
	cout << d1;
    cout << "\nDuration 2 : ";
	cout << d2;
    cout << "\nTotal Duration : ";
	cout << d3;
	
	cout << "\nTotal time in seconds " << timeInSec << endl;    
    return 0;
}

