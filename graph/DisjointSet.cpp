#include<iostream>
#define LL long long int
#define LIM 100005
using namespace std;
int p[LIM],n; // p is for parent
int rank[LIM];
void create_set()
{
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
        rank[i]=0;
    }
}
int find_set(int x)
{
    if(x==p[x])
        return x;
    else    
    {
        p[x]=find_set(p[x]);
        return p[x];
    }           
}
void merge_sets(int x,int y)
{
    int px,py;
    px=find_set(x);
    py=find_set(y);
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
int main()
{
    cin>>n; 
    create_set();
    int a,b,q,i;
    cin>>q; // queries
    while(q--)
    {
        cin>>a>>b;
        merge_sets(a,b);
    }
    for(i=1;i<=n;i++)
    {
        cout<<find_set(i)<<endl;   
    }
    return 0;
}
