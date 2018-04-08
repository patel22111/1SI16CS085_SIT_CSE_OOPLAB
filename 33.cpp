#include<iostream>
#include<cstring>
using namespace std;

class StringType
{
    char *name;
    int length;
    
    public:
    
    StringType();
    ~StringType();
    StringType(const char*);
    void display();
    void join(StringType &a, StringType &b);
};

StringType :: StringType()
{
    length = 0;
    name = new char[length+1];
}

StringType :: ~StringType()
{
    cout << "\nString with content " << name << " deallocated\n"; 
    delete name;
}

StringType :: StringType(const char *s)
{
    length = strlen(s);
    name = new char[length+1];
    strcpy(name, s);
}

void StringType :: display()
{
    cout << name << "\n";
}

void StringType :: join(StringType &a, StringType &b)
{
    length = a.length + b.length;
    delete name;
    name = new char[length+1];
    strcpy(name,a.name);
    strcat(name,b.name);
}

int main()
{
    char *first = (char*)"Richard ";
//    char *first;
//    strcpy(first, "Richard ");

    StringType name1(first), name2("Matthew "), name3("Stallman"), s1, s2;
    
    s1.join(name1, name2);
    s2.join(s1, name3);
    {
        StringType s5("Somename");
        s5.display();   
    }
    
    //display all StringTypes
    name1.display();
    name2.display();
    name3.display();
    s1.display();
    s2.display();
    return 0;
}
