
//Constant Pointer to Constant Data
//const int *const ptr = &x;
//This declaration is read from right to left as " ptr is a constant pointer to an integer constant. " 

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int x = 6, y;
	const int * const ptr = &x; // const pointer must be initialized			
	
	cout << setw(4) << *ptr << endl;
	
//	*ptr = 7; // error: *ptr is const; cannot assign new value
//	ptr = &y; // error: ptr is const; cannot assign new address	
	x++;
	cout << *ptr << endl;
	return 0;
}
