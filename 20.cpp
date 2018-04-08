//Constant Pointer to Nonconstant Data
//int * const ptr = &x;
//The declaration is read from right to left as "ptr is a constant pointer to a nonconstant integer."

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int x, y;
	
	int * const ptr = &x; // const pointer must be initialized		
	*ptr = 7; // allowed: *ptr is not const
	cout << "\nx = " << x << endl;
	x++;		//Allowed
	cout << "\nx = " << x << endl;
	(*ptr)++;		//Allowed
	cout << "\nx = " << x << endl;

	ptr = &y; // error: ptr is const; cannot assign to it a new address
	return 0;
}
