#include<iostream>
#include<cstring>
#define SWAP(a,b) {typeof(a) temp=a;a=b;b=temp;}
using namespace std;
class array{
	
	public:int *a;
	private:int s;
	public:array(int n)
	{
		s=n;
		a=new int[n];
	}
	array(int n,int x)
	{
		s=n;
		a=new int[n];
		memset(a,x,sizeof(a));
	}
	
	sort()
	{
		for(int i=0;i<s-1;i++)
		{
			int min=i;
			for(int j=i+1;j<s;j++)
			{
				if(a[min]>a[j])
				{
					min=j;	
				}
			}
			
			SWAP(a[min],a[i]);
		}
	}
	int size()
	{
		return s;
	}
	
};
int main()
{
	int n;
	cin>>n;

	array A(n);
	for(int i=0;i<n;i++)
	{
		cin>>A.a[i];
	}
	A.sort();
	for(int i=0;i<n;i++)
	{
		cout<<A.a[i]<<" ";
	}
	return 0;
}
