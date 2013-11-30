#include <iostream>
using namespace std;
#include <vector>
#include <cstdlib>
#include <algorithm>

struct node
{
	int data;
	node* next;
	node(int x)
	{
		data=x;
		next=NULL;
	}
};

struct linked_list
{
    node* head;
    linked_list()
    {
    	head=NULL;
    }
};



node* InsertNth(node *&head, int data, int position)
{
  // Complete this method only
  // Do not write main function. 
  node* p=new node(data);
  p->data=data;
  p->next=NULL;
    
  if(position==0)
  {
     p->next=head;
     head=p;
     return head;
  }
  node* temp=head;
  node* store_next=head->next;
  while(position>1)
  {
      temp=temp->next;
      if(temp->next==NULL)
          store_next=NULL;
      else
          store_next=temp->next;
      position--;
  }
   (*temp).next=p;
    p->next=store_next;
   return head;
}

void insert(linked_list &l,int x)
{
	 node* p=new node(x);
     if(l.head==NULL)
         l.head=p;
     else
     { 
     	node* temp=l.head;
        while (temp->next!=NULL)
     	 temp=temp->next;
        (*temp).next=p;
     }
}

void display(linked_list &l)
{
	if(l.head==NULL)
		return;
	node* temp=l.head;
	while(temp!=NULL)
		{cout<<temp->data<<"  ";
	     temp=temp->next;
	    }
	    cout<<endl;
}

void reverse_link(linked_list &l,int k,node* &start)
{
  if (start==NULL)
    return;
  if (k==1)
  	return;
  vector<int> keys;
  node* temp=start;
  node* end=NULL;
  int count=0;
  while(temp!=NULL||count<=k)
 {
     count++;
     keys.push_back(temp->data);
     if(count==k)
     {
     	end=temp;
     	break;
     }
     temp=temp->next;
 }
 reverse(keys.begin(),keys.end());
 
 temp=start;
 count=0;
 while(count<keys.size())
 {
 	(*temp).data=keys[count];
 	count++;
 	temp=temp->next;
 }
  reverse_link(l,k,end->next);

}

void reverse(node* &head)
{
  if(head==NULL)
    return;
  if(head->next==NULL)
    return;
  node* prev=NULL;
  node* next_node=head;
  while(next_node!=NULL)
  {
    node* temp_store=next_node->next;
    (*next_node).next=prev;                //point back
    prev=next_node;
    next_node=temp_store;
  }
  head=prev;

}

int main()
{
	linked_list l;
    int a[]={1,2,3,4,5,6};
    int i;
    for(i=0;i<6;i++)
      insert(l,a[i]);
    reverse(l.head);
    display(l);
    return 0;
}