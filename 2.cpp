#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class RandomInt
{
	public:
	RandomInt(int ia, int ib);
	int operator()();
	int operator()(int nb);
	int operator()(int na, int nb);
	private:
	int a, b;
};
RandomInt::RandomInt(int ia, int ib) : a(ia), b(ib) 
{
}

int RandomInt::operator()()
{
	return a + rand() % (b - a + 1);
}

int RandomInt::operator()(int nb)
{
	return a + rand() % (nb - a + 1);
}

int RandomInt::operator()(int na, int nb)
{
	return na + rand() % (nb - na + 1);
}

int main()
{
	RandomInt r(3, 7);
	
	srand(time(NULL));
	//r.operator()()
	cout << "random value between 3 and 7 " << r() << "\n";
	//r.operator()(10)
	cout << "random value between 3 and 10 " << r(10) << "\n";
	//r.operator()(23,30)
	cout << "random value between 23 and 30 " << r(23, 30) << "\n";
	return 0;
}
