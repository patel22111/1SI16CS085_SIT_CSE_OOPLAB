#include <iostream>
#include<cmath>
using namespace std;

typedef struct{
	int xC, yC;
}POINT;

typedef struct{
	POINT lt, rb;
}RECTANGLE;


int fnCalcAreaRect(const RECTANGLE&);
void fnReadPoint(POINT&);
void fnReadRectangle(RECTANGLE&);


int main(void)
{
	RECTANGLE r1;	
	int iArea;
	fnReadRectangle(r1);
	iArea = fnCalcAreaRect(r1);	
	cout << "\nArea of the Rectangle is " << iArea << " units" << endl;
	return 0;
}

void fnReadPoint(POINT& p)
{
	cin >> p.xC >> p.yC;
}

void fnReadRectangle(RECTANGLE& r)
{
	cout << "\nEnter the coordinates of the Left Top \n";
	fnReadPoint(r.lt);
	cout << "\nEnter the coordinates of the Right Bottom \n";
	fnReadPoint(r.rb);
}

int fnCalcAreaRect(const RECTANGLE& r) 
{
	int iLen, iBrd;
//	(r.rb.xC)+=1;	//should not be allowed
	iLen = abs(r.rb.xC - r.lt.xC);
	iBrd = abs(r.rb.yC - r.lt.yC);
	cout << iLen << " * " << iBrd << endl;	
	return iLen *iBrd;
}
