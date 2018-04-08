#include <iostream>
#include <cstdlib>
using namespace std;
class SafeArray {
    int sz;
    int *Arr;
    public:
    SafeArray(int s) 
    {  
        sz = s;
        Arr = new int[sz];
    }
    ~SafeArray()
    {
    	delete [] Arr;
    }
    int& operator[](int x);
    friend ostream& operator<<(ostream& os, const SafeArray& ia);
    friend istream& operator>>(istream& is, SafeArray& ia);
};

int& SafeArray ::operator[](int x) 
{
    if(x < 0 || x >= sz)
    {
        cout << "out of range" << endl;
        exit(0);
    }
    else
        return Arr[x];
}

ostream& operator<<(ostream& os, const SafeArray& ia) 
{
	cout << "\nArray contents are : " << endl;
    for(int j = 0; j < ia.sz; j++) 
    {
        os << ia.Arr[j];
        if(j != ia.sz -1)
            os << ", ";
    }
    os << endl;
    return os;
}

istream& operator>>(istream& is, SafeArray& ia)
{
	cout << "\nEnter " << ia.sz << " elements into the array : " << endl;
    for(int j = 0; j < ia.sz; j++)
        is >> ia.Arr[j];
    return is;
}
int main() 
{
    int size, value;
	int iIndex, i, iValAtIndex;
    cout << "Enter array size :\n";
    cin >> size;
    SafeArray sArr(size);
    cin >> sArr;
    cout << sArr;


	cout << "\nEnter an array index : ";
	cin >> iIndex;
	
	iValAtIndex = sArr[iIndex];
	
	cout << "Value at Index " << iIndex << " is " << iValAtIndex << endl;

    value = sArr[2];
    cout << value <<endl;
//    value = sArr[-3];
//    value = sArr[size];
    sArr[1] = sArr[2]+1;   
    cout << sArr;        
    sArr[-2] = 0;
    return 0;
}
