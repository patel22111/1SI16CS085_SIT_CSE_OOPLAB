    #include<iostream>
    using namespace std;

    const int MAX = 4;

    class Stack
    {
	    protected:
	    int st[MAX];
	    int top;

	    public:
	    Stack()	{ top = 0; }
	    void push(int var)	{   st[++top] = var;    }
	    int pop()	{   return st[top--];   }
    };

    class Stack2: public Stack
    {
	    public:
	    void push(int var)
	    {
		    if(top < MAX)
			    Stack::push(var);
		    else
			    cout << "\nError Stack is Full\n" << endl;
	    }
	    int pop()
	    {
		    if(top > 0)
			    return Stack::pop();
		    else
		    {
		    	cout << "\nError Stack is Empty\n" << endl;
		    	return -1;
		    }
			    
	    }
    };

    int main(void)
    {
	    Stack2 s1;
	    Stack s;
	    s.pop();

        s.push(23);
        
	    s1.push(11);
	    s1.push(22);
	    s1.push(33);

	    cout << endl << s1.pop();
	    cout << endl << s1.pop();
	    cout << endl << s1.pop();
	    cout << endl << s1.pop();

	    return 0;
    }
