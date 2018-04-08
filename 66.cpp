#include <iostream>
using namespace std;

class Resistance_Pair
{
	protected:
		double r1, r2;
	public:
		void read_data();
		virtual double calc_resistance()=0;
};

class Series_resistance_Pair : public Resistance_Pair
{
	public:
		double calc_resistance();
};

class Parallel_resistance_Pair : public Resistance_Pair
{
	public:
		double calc_resistance();
};

void Resistance_Pair::read_data()
{
	cout<<"Enter 2 resistances."<<endl;	
	cin>>r1>>r2;
}

double Series_resistance_Pair::calc_resistance()
{
	return (r1+r2);
}

double Parallel_resistance_Pair::calc_resistance()
{
	return (1/(1/r1+1/r2));
}


int main()
{
	Resistance_Pair* ptr[4];

	int i;
	char name;
	double denominator, total_resistance;

	for (i=0; i<4; i++)
	{
		cout<<"Enter type (s or p)"<<endl;
		cin>>name;

		if (name=='s')
		{
			ptr[i] = new Series_resistance_Pair;
		}
		else
		{
			ptr[i] = new Parallel_resistance_Pair;
		}

		ptr[i]->read_data();
	}

	denominator = 0;
	for (i=0; i<4; i++)  
		denominator += 1/ptr[i]->calc_resistance();
	total_resistance = 1/denominator;

	cout<<"Total resistance = "<<total_resistance<<endl;
	return 0;
}

