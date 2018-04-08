#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
//	const int x;
//	x = 7; 
	const int x = 7; // initialized constant variable
	cout << "The value of constant variable x is: " << x << endl;
//	x = 5;	//error

	const int arraySize = 10;
	int s[ arraySize ]; // array s has 10 elements
	
	for ( int i = 0; i < arraySize; ++i ) // set the values
		s[i] = 2 + 2 * i;
		
	cout << "Element" << setw(13) << "Value" << endl;
	// output contents of array s in tabular format
	for ( int j = 0; j < arraySize; ++j )
		cout << setw(7) << j << setw(13) << s[j] << endl;
	return 0;
}
