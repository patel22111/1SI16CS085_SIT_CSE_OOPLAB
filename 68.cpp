#include <iostream>
using namespace std;

int main()
{
	int *ptr;
	int iaArr[10], i;
	
	ptr = iaArr;		// ptr = &iaArr[0];
	
	cout << "\nEnter array elements\n";
	for(i=0;i<5;i++)
	{
		cin >> ptr[i];
		//cin >> *(ptr+i);
		//cin >> *(i+ptr);
		//cin >> *(iaArr+i);
		//cin >> iaArr[i];
		//cin >> i[iaArr];
		
	}
	
	cout << "\nArray contents are\n";
	for(i=0;i<5;i++)
	{
		cout << iaArr[i];
		//cout << *(ptr+i);
		//cout << *(i+ptr);
		//cout << *(iaArr+i);
		//cout << iaArr[i];
		//cout << i[iaArr];
	}
	
	return 0;
}
