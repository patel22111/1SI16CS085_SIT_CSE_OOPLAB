#include <iostream>
using namespace std;

class Person{
    protected:
    char name[30];
    int age;
    char address[50];
    public:
    
    void getData()
    {
//        cout << "Base" << endl;
		cout << "Enter Name, Age and Address" << endl;
        cin >> name >> age >> address;
    }
    void showData()
    {
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
        cout << "Address : " << address << endl;
    }
};

class Student : public Person
{
    char usn[10];
    char college[20];
    public:
        void getStudData()
        {
//            cout << "Child" << endl;        
            getData();
            cout << "Enter USN and College" << endl;
            cin >> usn >> college;
        }
        void showStudData()
        {
            showData();
            cout << "USN : " << usn << endl;
            cout << "College : " << college << endl;            
        }
        
};

class Employee : public Person{
    char empid[10];
    char company[20];
    public:
        void getEmpData()
        {
            getData();
            cout << "Enter Employee ID and Company" << endl;
            cin >> empid >> company;
        }
        void showStudData()
        {
            showData();
            cout << "EmpID : " << empid << endl;
            cout << "Company : " << company << endl;            
        }
        
};

int main()
{
    Student s1;
    s1.getStudData();
    s1.showStudData();
    return 0;
}
