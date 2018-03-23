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
		int pivot;
		if(l<r)
		{
			pivot=partition(l,r);
			sort(l,pivot-1);
			sort(pivot+1,r);
		}
	}
	partition(int l,int r )
	{
		int piv=a[r];
		int i=l-1;
		for(int j=l;j<r;j++)
		{
			if(a[j]<piv)
			{
				i++;
				SWAP(a[i],a[j]);
			}
		}
		SWAP(a[i+1],a[r]);
		return i+1;
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
