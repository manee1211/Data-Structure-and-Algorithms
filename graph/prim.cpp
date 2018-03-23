#include<iostream>
#include<cstring>
#include<limits.h>
using namespace std;
int g[1000][1000];
int v;
#define LL long long int
#define LIM 100005
int p[LIM],n; // p is for parent
int rank[LIM];
#define SWAP(a,b) {typeof(a) temp=a;a=b;b=temp;}
struct Edge{
	int src,dest,weight;
};
struct pair1{
	int val;
	int x;
};
class MinHeap
{
    pair1 *harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap
public:
    // Constructor
    MinHeap(int cap)
    {
	    heap_size = 0;
	    capacity = cap;
	    harr = new pair1[cap];
	}
	int size()
	{
		return heap_size;
	}
    // to heapify a subtree with root at given index
    void MinHeapify(int i)
	{
	    int l = left(i);
	    int r = right(i);
	    int smallest = i;
	    if (l < heap_size && harr[l].val < harr[i].val)
	        smallest = l;
	    if (r < heap_size && harr[r].val < harr[smallest].val)
	        smallest = r;
	    if (smallest != i)
	    {
	        SWAP(harr[i], harr[smallest]);
	        MinHeapify(smallest);
	    }
	}

    int parent(int i) { return (i-1)/2; }

    // to get index of left child of node at index i
    int left(int i) { return (2*i + 1); }

    // to get index of right child of node at index i
    int right(int i) { return (2*i + 2); }

    // to extract the root which is the minimum element
    void extractMin()
	{
	    if (heap_size <= 0)
	        return ;
	    if (heap_size == 1)
	    {
	        heap_size--;
			return;
	    }
	
	    // Store the minimum value, and remove it from heap
	    harr[0] = harr[heap_size-1];
	    heap_size--;
	    MinHeapify(0);
	}

   

    // Returns the minimum key (key at root) from min heap
    pair1 getMin() { return harr[0]; }


    // Inserts a new key 'k'
    void insertKey(pair1 k)
	{
	    if (heap_size == capacity)
	    {
	        cout << "\nOverflow: Could not insertKey\n";
	        return;
	    }
	
	    // First insert the new key at the end
	    heap_size++;
	    int i = heap_size - 1;
	    harr[i] = k;
	
	    // Fix the min heap property if it is violated
	    while (i != 0 && harr[parent(i)].val > harr[i].val)
	    {
	       SWAP(harr[i], harr[parent(i)]);
	       i = parent(i);
	    }
	}
};



void prim(Edge edge[],int e)
{
	MinHeap q(15);
	int *vis=new int[v];

	int parent[v];
	int key[v];
	for(int i=0;i<v;i++)
	{
		key[i]=INT_MAX;
		parent[i]=-1;
		vis[i]=0;
	}
	parent[0]=-1;
	key[0]=0;
	q.insertKey({0,0});
	int cost=0;
	while(q.size()!=0)
	{
		pair1 p=q.getMin();
		
		q.extractMin();
		int x=p.x;
		if(vis[x]==1)
		continue;
		vis[x]=1;
		cost+=p.val;
		for(int i=0;i<v;i++)
		{
			//cout<<i<<" "<<g[x][i]<<" "<<vis[i]<<endl;
			if(!vis[i]&&g[x][i]<key[i])
			{
				q.insertKey({g[x][i],i});
				parent[i]=x;
				key[i]=g[x][i];
			}
		
		}
	
	}
	cout<<cost;
	for(int i=0;i<v;i++)
	{
		cout<<parent[i]<<" ";
	}
}
int main()
{
	Edge edge[]={
		{0,1,10},{2,1,7},{0,2,5},{4,1,6},{2,3,3},{4,5,3},{4,0,3}
		
	};
	v=6;
	for(int i=0;i<v;i++)
	for(int j=0;j<v;j++)
	g[i][j]=INT_MAX;
	int e=sizeof(edge)/sizeof(edge[0]);
	for(int i=0;i<e;i++)
	{
		g[edge[i].src][edge[i].dest]=edge[i].weight;
		g[edge[i].dest][edge[i].src]=edge[i].weight;
	}
	
	prim(edge,e);
	return 0;
}
