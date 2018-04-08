#include <iostream>
#include <cstdlib>
#include <new>
using namespace std;
class MyClass
{
	int dummy;
	public:
	void* operator new(size_t size) = delete;
	void* operator new[](size_t size) = delete;
};

int main()
{
	MyClass obj;
//	MyClass* p1 = new MyClass;
//	MyClass* pArray = new MyClass[2];
	return 0;
}
