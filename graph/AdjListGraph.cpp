#include<iostream>
using namespace std;
struct Node{
	int val;
	Node *next;
};
struct Edge{
	int src,dest;
};
class Graph{
	int V;
	Node* getNewNode(int dest,Node* head)
	{
		Node* newNode=new Node;
		newNode->val=dest;
		newNode->next=head;
		return newNode;
	}
	public:
		Node **head;
		Graph(Edge edge[],int e,int v)
		{
			head=new Node*[v]();
			this->V=v;
			for(int i=0;i<v;i++)
			{
				head[i]=NULL;
			}
			
			for(int i=0;i<e;i++)
			{
				int s=edge[i].src;
				int d=edge[i].dest;
				Node* newNode = getNewNode(d,head[s]);
				head[s]=newNode;
				//for undirected graph
				newNode=getNewNode(s,head[d]);
				head[d]=newNode;
			}
			
		}
		~Graph()
		{
			for(int i=0;i<V;i++)
			{
				delete[] head[i];
			}
			delete[] head;
		}
		void print()
		{
			for(int i=0;i<V;i++)
			{
				Node* temp=head[i];
				cout<<i<<"-->";
				while(temp!=NULL)
				{
					cout<<temp->val<<"->";
					temp=temp->next;
				}
				cout<<endl;
			}
		}
};
int main()
{
	Edge edge[]={
		{0,1},{2,1},{0,2},{4,1},{2,3},{4,5}
	};
	int v=6;
	int e=sizeof(edge)/sizeof(edge[0]);
	Graph g(edge,e,v);
	g.print();
	return 0;
}
