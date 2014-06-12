#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>

struct node
{
	node* next;
	int data;
	node() {next=NULL;}
};

struct linked_list
{
	node* head;
	node* tail;
	linked_list() {head=tail=NULL;}
};

void insert(linked_list &l,int d)
{
	node* p=new node();
	p->data=d;
	node* temp=l.head;
	if(temp==NULL)
	{
		l.head=l.tail=p;
		return;
	}
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=p;
	l.tail=p;
}

void show(const linked_list &l)
{
	node* temp=l.head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

void reverse(linked_list &l,node* t)
{
	if(t==NULL) return;

	if(t->next==NULL)
	{
		l.head=t;
		l.tail=t;
		return;
	}
	node* temp=t->next;
	t->next=NULL;
	reverse(l,temp);
	temp->next=t;
	l.tail=t;
}

int main()
{
	int a[]={1,2,3,4,5,6};
	vector<int> v(a,a+sizeof(a)/sizeof(a[0]));
	linked_list my_obj;
	for(int i=0;i<v.size();i++)
		insert(my_obj,v[i]);
    reverse(my_obj,my_obj.head);
    show(my_obj);
}