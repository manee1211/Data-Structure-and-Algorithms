#include<iostream>
using namespace std;
#define LL long long int
#define LIM 100005
int p[LIM],n; // p is for parent
int rank[LIM];
#define SWAP(a,b) {typeof(a) temp=a;a=b;b=temp;}
struct Edge{
	int src,dest,weight;
};
int partition(Edge edge[],int l,int r )
{
	int piv=edge[r].weight;
	int i=l-1;
	for(int j=l;j<r;j++)
	{
		if(edge[j].weight<piv)
		{
			i++;
			SWAP(edge[i],edge[j]);
		}
	}
	SWAP(edge[i+1],edge[r]);
	return i+1;
}
void sort(Edge edge[],int l,int r)
{
	int pivot;
	if(l<r)
	{
		pivot=partition(edge,l,r);
		sort(edge,l,pivot-1);
		sort(edge,pivot+1,r);
	}
}
void initialize(int n)
{
    for(int i=0;i<n;i++)
    {
        p[i]=i;
        rank[i]=0;
    }
}
int parent(int x)
{
    if(x==p[x])
        return x;
    else    
    {
        p[x]=parent(p[x]);
        return p[x];
    }           
}
void union1(int x,int y)
{
    int px,py;
    px=parent(x);
    py=parent(y);
    if(rank[px]>rank[py])
        p[py]=px;
    else
    if(rank[py]>rank[px])
        p[px]=py;
    else
    if(rank[px]==rank[py])
    {
        p[px]=py;
        rank[py]++;
    }               
}
void kruskal(Edge edge[],int v,int e)
{
	Edge *result=new Edge[v];
	initialize(v);
	int i=0;
	int j=0;
	while(i<v-1)
	{
		Edge e=edge[j++];
		int x=parent(e.src);
		int y=parent(e.dest);
		if(x!=y)
		{
			result[i++]=e;
			union1(x,y);
		}
	}
	while(i--)
	{
		cout<<result[i].src<<result[i].dest<<result[i].weight<<endl;
	}
}
int main()
{
	Edge edge[]={
		{0,1,6},{2,1,7},{0,2,5},{4,1,6},{2,3,3},{4,5,3}
	};
	int v=6;
	int e=sizeof(edge)/sizeof(edge[0]);
	sort(edge,0,e-1);
	kruskal(edge,v,e);
	return 0;
}
