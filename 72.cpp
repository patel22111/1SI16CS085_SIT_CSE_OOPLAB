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
		    cout << "Basic to Class type Conversion" << endl;

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
	};

	int main()
	{
		float mtrs;
		//Basic type to Class Conversion 
		Distance dist1(2.35F);   //uses 1-arg constructor to convert meters to Distance
		cout << "\ndist1 = "; dist1.showdist();
		
		cout << "\n=========================" << endl;
		cin.get();
		
		Distance dist2(7, 10.25);    //uses 2-arg constructor
		dist2.showdist();    
		cout << "\n=========================" << endl;
		cin.get();

		dist2 = 2.35F;    // uses explicit constructor
		cout << "\ndist2 = " ; dist2.showdist();
		cout << "\n=========================" << endl;
		cin.get();

		return 0;
	}

