// conversions: Distance to meters, meters to Distance
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
class Distance
//English Distance class
{
    private:
    static const float MTF = 3.280833F;    //meters to feet
    int feet;
    float inches;
    public:
    //constructor (no args)
    Distance() : feet(0), inches(0.0)
    { }
    //constructor (one arg)		basic to Class type	float to Distance
    Distance(float meters) 
    {
        //convert meters to Distance
        float fltfeet = MTF * meters; //convert to float feet
        feet = int(fltfeet);    //feet is integer part
        inches = 12*(fltfeet-feet);    //inches is what's left
        cout << "\nOne arg\n";

    }
    //constructor (two args)
    Distance(int ft, float in) : feet(ft),inches(in)
    {
        cout << "\nTwo args\n";
    }
    
    void getdist()    //get length from user
    {
        cout << "\nEnter feet: "; cin >> feet;
        cout << "Enter inches: "; cin >> inches;
    }
    
    void showdist() const    //display distance
    {
        cout << feet << "\':" << inches << '\"'; 
    }
    
    operator float() const    //conversion operator
    {
        //converts Distance to meters
        cout << "\nconversion operator\n";
        float fracfeet = inches/12;        //convert the inches
        fracfeet += static_cast<float>(feet); //add the feet
        return fracfeet/MTF;        //convert to meters
    }
    void operator=(float meters)
    {
        float fltfeet = MTF * meters; //convert to float feet
        feet = int(fltfeet);    //feet is integer part
        inches = 12*(fltfeet-feet);    //inches is what's left
        cout << "\nOverload =\n";
    
    }
};


int main()
{
    float mtrs;
    //Basic type to Class Conversion 
    Distance dist1(2.35F);   //uses 1-arg constructor to convert meters to Distance
    cout << "\ndist1 = "; dist1.showdist();
    
    cout << "\n=========================" << endl;
	cin.get();
    //Class to Basic type Conversion
    mtrs = static_cast<float>(dist1); //uses conversion operator for Distance to meters
    cout << "\ndist1 = " << mtrs << " meters\n";
    cout << "\n=========================" << endl;
    cin.get();
    
    Distance dist2(7, 10.25);    //uses 2-arg constructor
    
    mtrs = dist2;    //also uses conversion op
    cout << "\ndist2 = " << mtrs << " meters\n";
    cout << "\n=========================" << endl;
    cin.get();
//    Distance d3;
//    d3.showdist();
//    //Basic type to Class Conversion     
//    d3 = 4.5;
//    d3.showdist();
//    d3 = 7.8;
//    d3.showdist();
    dist2 = mtrs;        
    cout << "\ndist2 = "; dist2.showdist();
    cout << endl;
    
    dist2 = Distance(4, 8.8);        
    cout << "\ndist2 = "; dist2.showdist();
    cout << endl;
    return 0;
}

