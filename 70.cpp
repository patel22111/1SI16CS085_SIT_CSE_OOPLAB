#include <iostream>                           
using namespace std;

void fnCommuteTime( double = 40, double = 25);
//void fnCommuteTime( double vel = 40, double dist = 25);

int main(void)
{
	fnCommuteTime();
	fnCommuteTime(70);
	fnCommuteTime(30,20);

	return 0;
}

void fnCommuteTime( double velocity, double distance)
{
	cout<<"The Commute time is " << distance/velocity << " hours" << endl;
}
