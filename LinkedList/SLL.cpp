#include<iostream>
#include<cstring>
#define SWAP(a,b) {typeof(a) temp=a;a=b;b=temp;}
using namespace std;

class LinkedList{
	public:
	int val;
	LinkedList* next;
	LinkedList(int data){
		val=data;
		next=NULL;
	}
};
void add(LinkedList** head,int data)
{
	if(*head==NULL)
	{
		*head=new LinkedList(data);
	}
	else
	{
		(*head)->next=new LinkedList(data);
		*head=(*head)->next;
	}
	//return head;
}


int main()
{
	LinkedList* head=NULL;
	LinkedList* tail;;
	add(&head,2);
	tail=head;
	add(&tail,3);
	add(&tail,4);
	add(&tail,5);
	while(head!=NULL)
	{
		cout<<head->val<<" ";
		head=head->next;
	}

	return 0;
}
