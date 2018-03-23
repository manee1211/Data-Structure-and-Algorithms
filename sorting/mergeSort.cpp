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
		
		int mid;
		if(l<r)
		{
			mid=(l+r)/2;
			sort(l,mid);
			sort(mid+1,r);
			cout<<l<<mid+1<<r<<endl;
			merge(l,mid+1,r);
		}
	}
	merge(int l,int mid,int r )
	{
		int i=l;
		int left_end=mid-1;//left end
		int j=mid;
		int n=r-l+1;
		int temp[n];
		int k=0;
		while(i<=left_end&&j<=r)
		{
			if(a[i]<a[j])
			{
				temp[k++]=a[i++];
			}
			else
			{
				temp[k++]=a[j++];
			}
		}
		while(i<=left_end)
		temp[k++]=a[i++];
		while(j<=r)
		temp[k++]=a[j++];
		i=0;
		for(j=l;j<n;j++)
		a[j]=temp[i++];
		//cout<<endl;
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
	A.sort(0,A.size()-1);
	for(int i=0;i<n;i++)
	{
		cout<<A.a[i]<<" ";
	}
	return 0;
}
