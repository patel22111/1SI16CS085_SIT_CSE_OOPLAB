#include<iostream>
using namespace std;
//Nonconstant Pointer to Nonconstant Data
//int *ptr

// Attempting to modify data through a 
// nonconstant pointer to Nonconstant data.

void fetchModify( int * ); // prototype

int main()
{
   int iaArr[10] = {1,2,3,4,5,6,7,8,9,10};
   int iaArr2[10] = {1,2,3,4,5,6,7,8,9,10};

   fetchModify(iaArr); // function attempts modification
   fetchModify(iaArr2); // function attempts modification
   
   return 0;
} // end main

// xPtr can modify the value of variable to which it points
void fetchModify( int *xPtr )
{
	int i;
	for(i=0;i<10;i++)
		cout << xPtr[i];		//*(xptr+i)
	cout << endl;
	for(i=0;i<10;i++)
		xPtr[i] = 0;
	cout << endl;
	for(i=0;i<10;i++)
		cout << xPtr[i];
	cout << endl;
} // end function 


