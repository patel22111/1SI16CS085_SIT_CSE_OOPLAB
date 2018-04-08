#include <iostream>
using namespace std;

class Box
{
    protected:
    double length ;
    double width ;
    double height ;
     
    public:
    Box() { length = width = height = 1.0; }
    Box(double lv, double wv, double hv) : length(lv), width(wv), height(hv) {}

         
    // Function to show the volume of an object
    void showVolume() const
    { cout << "Box usable volume is " << volume() << endl; }
     
    // Function to calculate the volume of a Box object
    virtual double volume() const { return length*width*height; }
};


class ToughPack : public Box
{
    public:
    // Constructor
    ToughPack(double lv, double wv, double hv) : Box (lv, wv, hv) {}
     
    // Function to calculate volume of a ToughPack allowing 15% for packing
    double volume() const { return 0.85*length*width*height; }
};


//illustrates static or early binding - resolved at compile time
int main()
{
    Box box(20.0, 30.0, 40.0);
    // Define a box
    ToughPack hardcase(20.0, 30.0, 40.0);
    // Declare tough box - same size
     
    box.showVolume();
    // Display volume of base box
    hardcase.showVolume();
    // Display volume of derived box
    
    Box *pBox;

    pBox = &box;
    pBox->showVolume();
    
    pBox = &hardcase;    
    pBox->showVolume();
    cout << "hardcase volume through pBox is " << pBox->volume() << endl;

    return 0;
}

