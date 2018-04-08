#include<iostream>
#include <cmath>
using namespace std;

inline float fnCircumference( float );
inline float fnCalcArea( float );

int main(void)
{
	float rad;

	cout << "\nEnter the radius of the circle" << endl;
	cin >> rad;

	cout << "\nThe Circumference of the circle is " << fnCircumference(rad) << endl;
	cout << "\nThe Area of the circle is " << fnCalcArea(rad) << endl;

	return 0;
}


inline float fnCircumference( float radius )
{
	return 2* M_PI * radius;
}

inline float fnCalcArea( float radius )
{
	return M_PI * radius * radius;
}


