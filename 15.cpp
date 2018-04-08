#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int *ptr;
    int size,i;
    
    cout << "\nEnter array size : ";
    cin >> size;
    srand(time(NULL));
    try
    {
        ptr = new int[size];
        
        for(i=0;i<size;i++)
        {
            *(ptr+i) = rand()%100;
        }
        cout << "\nArray Contents\n";
        for(i=0;i<size;i++)
        {
            cout << ptr[i] << "\t";
        }
        cout << endl;
        delete [] ptr;
    }catch(bad_alloc ba)
    {
        cout << "Allocation error....";
        return 1;    
    }
    return 0;
}
