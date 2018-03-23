#include<iostream>
#include<cstring>
using namespace std;
int g[1000][1000];
int v;
struct Edge{
	int src,dest;
};
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
void dfs()
{
	stack st(10);
	int vis[v];
	memset(vis,0,sizeof(vis));
	st.push(0);vis[0]=1;
	while(!st.isEmpty())
	{
		int s=st.top();
		st.pop();
		
		cout<<s<<" ";
		for(int i=0;i<v;i++)
		{
			if(!vis[i]&&g[s][i]==1)
			{
				st.push(i);
				vis[i]=1;
			}
		}
	}	
}
void bfs()
{
	queue st(v);
	int vis[v];
	memset(vis,0,sizeof(vis));
	st.push(0);
	vis[0]=1;
	while(!st.isEmpty())
	{
		int s=st.front();
		st.pop();
		
		cout<<s<<" ";
		for(int i=0;i<v;i++)
		{
			if(!vis[i]&&g[s][i]==1)
			{
				st.push(i);
				vis[i]=1;
			}
		}
	}	
}
int main()
{

	Edge edge[]={
		{0,1},{2,1},{0,2},{4,1},{2,3},{4,5}
	};
	int e=sizeof(edge)/sizeof(edge[0]);
	v=6;
	memset(g,0,sizeof(g));
	
	for(int i=0;i<e;i++)
	{
		g[edge[i].src][edge[i].dest]=1;
		g[edge[i].dest][edge[i].src]=1;
	}
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			cout<<g[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"dfs:";
	dfs();

	cout<<"\nbfs:";
	bfs();
	
}
