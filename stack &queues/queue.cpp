#include<iostream>
#include<cstring>
#define SWAP(a,b) {typeof(a) temp=a;a=b;b=temp;}
using namespace std;
class queue{
	
	private:
	int *a;
	int index;
	int rear;
	int cap;
	int count;
	public:queue(int n)
	{
		index=count=0;
		rear=n-1;
		cap=n;
		a=new int[n];
	}
	void push(int x)
	{
		if(!isFull())
		{
			rear=(rear+1)%cap;
			a[rear]=x;
			count++;
		}
		else
		cout<<"queue is full"<<endl;
	}
	void pop()
	{
		if(!isEmpty())
		{
			index=(index+1)%cap;
			count--;
		}
		else
		{
			cout<<"stack is empty"<<endl;
		}
	}
	int front()
	{
		if(!isEmpty())
		return a[index];
		else
		cout<<"stack is empty"<<endl;
	}
	bool isEmpty()
	{
		if(count==0)
		return true;
		return false;
	}
	bool isFull()
	{
		if(count==cap-1)
		return true;
		return false;
	}
	int size()
	{
		return count;
	}
	
};
int main()
{
	queue q(100000);
	
	cout<<q.isEmpty()<<endl;
	cout<<q.isFull()<<endl;
	q.push(5);
	cout<<q.front();

	return 0;
}
