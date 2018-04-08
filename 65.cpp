#include <iostream>
using namespace std;
class number {
	protected:
		int val;
	public:
		void setval(int i) { val = i; }
		// show() is a pure virtual function
		virtual void show() = 0;
};

class hextype : public number {
	public:
	void show() {
		cout << hex << val << "\n";
	}
};

class dectype : public number {
	public:
	void show() {
		cout << val << "\n";
	}
};

class octtype : public number {
	public:
	void show() {
		cout << oct << val << "\n";
	}
};
int main()
{
	dectype d;
	hextype h;
	octtype o;
	int iVal;
	
	cout << "\nEnter a number : ";
	cin >> iVal;
	
	
	d.setval(iVal);
	cout << "\nEntered value in decimal is : ";
	d.show(); 
	
	h.setval(iVal);
	cout << "\nEntered value in hexadecimal is : ";
	h.show(); 
	
	o.setval(iVal);
	cout << "\nEntered value in octal is : ";
	o.show(); 
	return 0;
}
