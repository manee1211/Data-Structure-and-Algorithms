#include<iostream>
#include<cstring>
#define SWAP(a,b) {typeof(a) temp=a;a=b;b=temp;}
using namespace std;
class stack{
	
	private:
	int *a;
	int index;
	int cap;
	public:stack(int n)
	{
		index=-1;
		cap=n;
		a=new int[n];
	}
	void push(int x)
	{
		if(!isFull())
		{
			index++;
			a[index]=x;
		}
		else
		cout<<"stack is full"<<endl;
	}
	void pop()
	{
		if(!isEmpty())
		{
			index--;
		}
		else
		{
			cout<<"stack is empty"<<endl;
		}
	}
	int top()
	{
		if(!isEmpty())
		return a[index];
		else
		cout<<"stack is empty"<<endl;
	}
	bool isEmpty()
	{
		if(index==-1)
		return true;
		return false;
	}
	bool isFull()
	{
		if(index==cap-1)
		return true;
		return false;
	}
	int size()
	{
		return index+1;
	}
	
};
int main()
{
	stack st(100000);
	
	cout<<st.isEmpty()<<endl;
	cout<<st.isFull()<<endl;
	st.push(5);
	cout<<st.top();

	return 0;
}
