#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Box
{
	protected:
	double length;
	double width;
	double height;
	 
	public:
	// Constructors
	Box(double lv, double wv, double hv) : length (lv), width (wv), height (hv) {}
	Box(): length (1.0), width (1.0), height (1.0){}		// No-arg constructor
	 
	double volume() const	// Function to calculate the volume
	{ return length*width*height; }
	 
	// Accessors
	double getLength() const { return length; }
	double getWidth() const { return width; }
	double getHeight() const { return height; }
	 
	friend ostream& operator<<(ostream& stream, const Box& box);
};

ostream& operator<<(ostream& stream, const Box& box)
{
	stream << " Box(" << setw(2) << box.length << ","
	<< setw(2) << box.width << ","
	<< setw(2) << box.height << ")";
	return stream;
}

class Carton : public Box
{
	private:
	string material;
	 
	public:
	Carton(const string desc = "Cardboard") : material(desc) {} // Constructor
//	Carton(double x, double y, double z, const string desc = "Cardboard") 
//	: material(desc), length (x), width (y), height (z){}
//	A derived class constructor cannot directly initialize base class members specified in the initialization list
	Carton(double x, double y, double z, const string desc = "Cardboard") 
	: material(desc), Box(x,y,z){}
	
//	Carton(double x, double y, double z, const string desc = "Cardboard") : material(desc)
//	{
//		length = x;
//		width = y;
//		height = z;
//	}
// 	will compile

	void showDetails()
	{
		cout << "\nMaterial = " << material;
		cout << "\nLength = " << length;
		cout << "\nWidth = " << width;
		cout << "\nHeight = " << height;
		cout << endl;
	}
	double carton_volume() { return length*width*height; }
};

int main()
{
	// Create a Box object and two Carton objects
	Box box (40.0, 30.0, 20.0);
	Carton carton( 10.0, 20.0, 30.0);
	Carton candyCarton (20.0, 30.0, 40.0, "Thin cardboard");
	 
	// Now volumes...
	cout << "box volume is " << box.volume() << endl;
	cout << "carton volume is " << carton.carton_volume() << endl;
	cout << "candyCarton volume is " << candyCarton.carton_volume() << endl;
	cout << "candyCarton length is " << candyCarton.getLength() << endl;
	
	candyCarton.showDetails();	
	carton.showDetails(); 
	return 0;
}
