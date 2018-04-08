#include <iostream>
#include <string>
using namespace std;

class petType
{
public:
//	void print(); 	// binding of the member function print in the body of the function 
					// callPrint occurred at compile time.
	virtual void print();
	petType(){}
	petType(string n){	name = n;	}

protected:
	string name;
};


void petType::print()
{
	cout << "Name: " << name;
}

class dogType: public petType
{
public:
	void print();
	dogType(){}
	dogType(string n, string b)
	{
		name = n;
		breed = b;
	}	

private:
	string breed;
};

void dogType::print()
{
	petType::print();
	cout << ", Breed: " << breed << endl;
}

void callPrint(petType *p);


int main()
{
	petType *q;
	dogType *r;
	q = new petType("Lucky");
	r = new dogType("Tommy", "German Shepherd");
	q->print();
	cout << endl;
	r->print();

	cout << "*** Calling the function callPrint ***" << endl;
	callPrint(q);

	cout << endl;
	callPrint(r);
	cout << endl;	
	return 0;
}

void callPrint(petType *p)
{
	p->print();
}



/* NOTES */
//virtual functions support run-time polymorphism
//a base-class pointer can be used to point to an object of any class derived from that base. 
//When a base pointer points to a derived object that contains a virtual function, 
//C++ determines which version of that function to call based upon the type of object 
//pointed to by the pointer. And this determination is made at run time. 
//Thus, when different objects are pointed to, different versions of the virtual
//function are executed. The same effect applies to base-class references.
//The binding of virtual functions occurs at program execution time, not at compile time. 
//This kind of binding is called run-time binding or late binding. 
//Run-time binding is also known as dynamic binding.



