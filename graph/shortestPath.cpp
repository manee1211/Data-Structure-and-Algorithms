#include<iostream>
#include<cstring>
#include<limits.h>
#define M "p"
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

void bellmann(Edge edge[],int e)
{
	int dis[v];
	for(int i=0;i<v;i++)
	dis[i]=INT_MAX;
	
	dis[0]=0;
	for(int i=0;i<v-1;i++)
	{
		for(int j=0;j<e;j++)
		{
			int s=edge[j].src;
			int d=edge[j].dest;
			int w=edge[j].weight;
			if(dis[s]!=INT_MAX&&dis[s]+w<dis[d])
			dis[d]=dis[s]+w;
		}
	}
	for(int i=0;i<v;i++)
	cout<<dis[i]<<" ";
}

void dijsktra()
{
	MinHeap q(15);
	int *vis=new int[v];
	int dis[v];
	for(int i=0;i<v;i++)
	{
		vis[i]=0;
		dis[i]=INT_MAX;
	}

	q.insertKey({0,0});
	dis[0]=0;
	while(q.size()!=0)
	{
		pair1 p=q.getMin();
		
		q.extractMin();
		int x=p.x;
		if(vis[x]==1)
		continue;
		vis[x]=1;
		for(int i=0;i<v;i++)
		{
			//cout<<i<<" "<<g[x][i]<<" "<<vis[i]<<endl;
			if(!vis[i]&&g[x][i]!=INT_MAX&&dis[x]!=INT_MAX&&(g[x][i]+dis[x]<dis[i]))
			{
				q.insertKey({g[x][i],i});
				dis[i]=g[x][i]+dis[x];
			}
		
		}
	
	}

	for(int i=0;i<v;i++)
	{
		cout<<dis[i]<<" ";
	}
}
void FloydWarshall()
{
	int dis[v][v];
	for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
    	{
    		dis[i][j]=g[i][j];
    		if(i==j)
    		dis[i][j]=0;
		}
//       for(int i=0;i<v;i++)
//	{
//		for(int j=0;j<v;j++)
//		{
//			cout<<dis[i][j]<<" ";
//		}
//		cout<<endl;
//	}     
//            
	for(int k=0;k<v;k++)
	{
		for(int i=0;i<v;i++)
		{
			for(int j=0;j<v;j++)
			{
				if(dis[i][k]!=INT_MAX&&dis[k][j]!=INT_MAX&&dis[i][j]>dis[i][k]+dis[k][j])
				{
					dis[i][j]=dis[i][k]+dis[k][j];
				}
			}
		}
	}
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			cout<<dis[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	Edge edge[]={
		{0,1,10},{0,4,3},{0,2,5},{1,2,7},{1,4,6},{2,3,3},{4,5,3},{4,1,2}
		
	};
	
	v=6;
	for(int i=0;i<v;i++)
	for(int j=0;j<v;j++)
	g[i][j]=INT_MAX;
	int e=sizeof(edge)/sizeof(edge[0]);
	for(int i=0;i<e;i++)
	{
		g[edge[i].src][edge[i].dest]=edge[i].weight;
		//g[edge[i].dest][edge[i].src]=edge[i].weight;
	}
	cout<<"bellmann:";
	bellmann(edge,e);
	cout<<endl;
	cout<<"Dijsktra:";
	dijsktra();
	cout<<endl;
	cout<<"Floyd:\n";
	FloydWarshall();
	return 0;
}
