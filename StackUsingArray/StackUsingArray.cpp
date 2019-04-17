#include<iostream>

#define MAX 100

using namespace std;

class stack
{
	private:
		int top;
	public:
		int iArray[MAX];
		stack()
		{
			top=-1;
		}	

		bool push(int x);
		int pop();
		bool isEmpty();
};

bool stack::push(int x)
{
	if(top>=MAX-1)
	{
		cout<<"\n\nThe stack is overflown\n";
		return false;
	}
	else
	{
		top=top+1;
		iArray[top]=x;
		return(true);
	}
}


int stack::pop()
{
	int popElement=0;
	if(top<=0)
	{
		cout<<"\nStack is underflow\n";
		return 0;
	}
	else 
	{
		top=top-1;
		popElement=iArray[top];
		
	}	
	return(popElement);
}

bool stack ::isEmpty()
{
	if(top==1)
	{
		return(true);
	}
}


int main()
{
	int x;
	stack s;
	s.push(10);
	s.push(20);
	s.push(30);

	for(int i=0;i<3;i++)
	{
		cout<<"\n\n element"<<s.iArray[i];
	}

	x=s.pop();
	cout<<"\nThe elemet pop from stack"<<x;

	x=s.pop();
	cout<<"\nThe elemet pop from stack"<<x;
	
	s.isEmpty();

	return 0;

}