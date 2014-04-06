#include <iostream>
using namespace std;
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <string>

struct node
{
	char data;
	node* p[27];  //one for each alphabet and one @a
	node()
	{
		for(int i=0;i<27;i++)
			p[i]=NULL;
	}
};

struct trie
{
	node* source;
	trie()
	{
		source=new node();
	}
};

void insert(trie &obj,node* cur_node,string d)
{
    if(d.length()==1)
    {
    	int child=d[0]-97;
    	node* z=new node();
    	z->data=d[0];
    	node* q=new node();
    	q->data='@';
        z->p[26]=q;
    	cur_node->p[child]=z;
    	return;
    }
    else
    {
    	int cur_char=d[0];
    	int child=cur_char-97;
        //check if that node is already there
        if(cur_node->p[child]==NULL)   //first time
        {
        	node* z=new node();
        	z->data=cur_char;
        	cur_node->p[child]=z;
        }
           	d.erase(d.begin());
        	insert(obj,cur_node->p[child],d);
    }
}

void show(trie &obj,node* cur_node,string s)
{
    //if cur_node->child[27]='@' print s;
    if(cur_node->p[26]!=NULL)
    {
    	cout<<s<<endl;
    }
    //scan through all possible alphabets;
    for(int i=0;i<26;i++)
    {
    	//go into new branch
    	if(cur_node->p[i]!=NULL)
    	{
    		show(obj,cur_node->p[i],s+char(97+i));
        }
    }
}


int main()
{
	trie obj;
    insert(obj,obj.source,"apple");
 
    insert(obj,obj.source,"applet");
    insert(obj,obj.source,"appearance");
    insert(obj,obj.source,"appeaxance");
    insert(obj,obj.source,"cppearance");
    insert(obj,obj.source,"bppearance");
    insert(obj,obj.source,"dppearance");
    
    show(obj,obj.source,"");
    return 0;
}