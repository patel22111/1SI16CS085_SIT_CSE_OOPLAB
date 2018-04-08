#include <iostream>
using namespace std;

class Celestial_body
{
	protected:
		double size;
	public:
		Celestial_body (double);
};

class Planet : public Celestial_body
{
	protected:
		double orbit_time;
	public:
		Planet (double, double);
};

class Earth : public Planet
{
	private:
		unsigned long int population;
	public:
		Earth();
};

Celestial_body :: Celestial_body (double size_var) : size(size_var)
{
	cout<<"Celestial_body constructor called."<<endl;
}

Planet :: Planet(double orbit_time_var, double size_var)
:Celestial_body(size_var), orbit_time(orbit_time_var)
{
	cout<<"Planet constructor called."<<endl;
}

Earth :: Earth(): Planet(1,40000), population(3000000000U)
{
	cout<<"Earth constructor called."<<endl;
	cout<<"Population = "<<population<<endl
		 <<"orbit time = "<<orbit_time<<endl
		 <<"size = "<<size<<endl;
}

int main()
{
	Earth earth;
	return 0;
}

