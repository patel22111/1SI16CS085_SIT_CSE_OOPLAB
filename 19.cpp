#include<iostream>
using namespace std;
//Nonconstant Pointer to Constant Data
//const int *ptr;
//The declaration is read from right to left as "ptr is a pointer to an integer constant." 

// Attempting to modify data through a 
// nonconstant pointer to constant data.

void fetchModify( const int * ); // prototype

int main()
{
   int iaArr[10] = {1,2,3,4,5,6,7,8,9,10};

   fetchModify(iaArr); // function attempts illegal modification
   
   iaArr[7] = 17;

   return 0;
} // end main

// xPtr cannot modify the value of constant variable to which it points
void fetchModify( const int *xPtr )
{
	int i;
	for(i=0;i<10;i++)
		cout << xPtr[i];
	cout << endl;
	for(i=0;i<10;i++)
		xPtr[i] = 0;
	cout << endl;
	for(i=0;i<10;i++)
		cout << xPtr[i];
	cout << endl;
} // end function f


