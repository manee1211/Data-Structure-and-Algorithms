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
	
	sort(int l,int r)
	{
		int k;
		cin>>k;//range of elements
		int c[k+1];
		for(int i=0;i<=k;i++)
		c[i]=0;
		
		for(int i=0;i<=r;i++)
		c[a[i]]++;
		
		for(int i=1;i<=k;i++)
		c[i]=c[i]+c[i-1];
		int b[r+1];
		for(int i=r;i>=0;i--)
		{
			b[c[a[i]]-1]=a[i];
			c[a[i]]--;
		}
		
		for(int i=0;i<=r;i++)
		a[i]=b[i];
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
	A.sort(0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<A.a[i]<<" ";
	}
	return 0;
}
