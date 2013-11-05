#include <iostream>
using namespace std;
#include <vector>
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

struct linked
{
    node* head;
    linked()
    {
    	head=NULL;
    }
    void push_back(int);
    void display();
};

void linked::push_back(int x)
{  
	node* p=new node(x);
	if(head==NULL)
      head=p;
    else
    {  node* temp=head;
    	while(temp!=NULL)
    	{  if(temp->next==NULL)
    		{   
    			(*temp).next=p;
    			break;
    		}
    		temp=temp->next;
    	}
    }
}

void linked::display()
{
	node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<"  ";
		temp=temp->next;
	}
	cout<<endl;
}

int main()
{
	int a[]={5,6,3};
	int b[]={8,4,2};
    linked list1,list2;
    int i;
   
    for(i=0;i<3;i++)
    {
    	list1.push_back(a[i]);
    	list2.push_back(b[i]);
    }

    linked out;


    return 0;
}