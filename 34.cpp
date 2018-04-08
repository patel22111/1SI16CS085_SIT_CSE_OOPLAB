#include <iostream>
using namespace std;

class Microwave
{
	int time, power_level;

	public:
		Microwave();
		Microwave(int);
		Microwave(int, int);
		void showdata();
};

Microwave :: Microwave()
          :time (60),power_level(10)
{
	cout << "No argument Constructor executed" << endl;
}

Microwave :: Microwave(int time_var)
          :time (time_var),power_level(10)
{
	cout << "One argument Constructor executed" << endl;
}

Microwave :: Microwave(int time_var, int power_level_var)
          :time (time_var),power_level(power_level_var)
{
	cout << "Two argument Constructor executed" << endl;
}

void Microwave :: showdata()
{
	cout << "Time = " << time << " Power Level = " << power_level << endl;
}

int main()
{
	Microwave mw1, mw2(30), mw3(45,6),mw4 = mw3;

	mw1.showdata();
	mw2.showdata();
	mw3.showdata();
	mw4.showdata();
	return 0;
}

