#include <iostream>
#include <string>
using namespace std;

class Polygon
{
    protected:
        int num_sides;
        double area;
        string name;
    public:
        Polygon();
        Polygon ( string, int );
        ~Polygon();
        void show_sides_area();

};

class Triangle : public Polygon
{
    private:
        double base, height;
    public:
        Triangle(double,double);
        ~Triangle();
        void calc_area();
};

class Square : public Polygon
{
    private:
        double side_length;
    public:
        Square(double);
        ~Square();
        void calc_area();
};

Polygon::Polygon()
{
    cout<<"Polygon constructor called."<<endl;
}

Polygon::Polygon(string name_var, int num_sides_var):
        num_sides(num_sides_var), area(0), name(name_var)
{
    cout<<"Polygon constructor called."<<endl;
}

Polygon::~Polygon()
{
    cout<<"Polygon destructor called."<<endl;
}

void Polygon::show_sides_area()
{
    cout<<name<<" "<<num_sides<<" sides, area = "<<area<<endl;
}

Triangle::Triangle(double base_var, double height_var):
         Polygon("Triangle", 3), base(base_var),  height(height_var)
{
    cout<<"Triangle constructor called."<<endl;
}

Triangle::~Triangle()
{
    cout<<"Triangle destructor called."<<endl;
}

void Triangle::calc_area()
{
    area = 0.5* base*height;
}

Square::Square (double side_length_var):
         Polygon("Square", 4), side_length(side_length_var)
{
    cout<<"Square constructor called."<<endl;
}

Square::~Square()
{
    cout<<"Square destructor called."<<endl;
}

void Square::calc_area()
{
    area = side_length * side_length;
}

int main()
{
    Triangle triangle1(3.5, 2);
    Square square1(2.5);

    triangle1.calc_area();
    triangle1.show_sides_area();
    square1.calc_area();
    square1.show_sides_area();

    cin.get();
    Polygon polygon1(triangle1), polygon2(square1);
//	Polygon polygon1, polygon2;
//    polygon1 = triangle1;
//    polygon2 = square1;

    polygon1.show_sides_area();
    polygon2.show_sides_area();
    return (0);
}

