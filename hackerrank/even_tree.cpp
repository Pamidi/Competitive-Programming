#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <list>
#include <cstdlib>

struct graph
{
	int n;
	int m;
	vector<list<int> > adj;

	graph(int v,int e)
	{
       n=v;
       m=e; 
       adj.resize(v+1);     
    }

	void add_edge(int u,int v)
	{
      adj[u].push_front(v);
      adj[v].push_front(u);
	}

    void display_adj_list()
    {
        for(int i=1;i<=n;i++)
        {
            cout<<"VERTEX "<<i<<" :";
            for(list<int>::iterator it=adj[i].begin();it!=adj[i].end();++it)
                cout<<*it<<" ";
            cout<<endl;
        }
    }
};

int calculate_children_nodes(graph &G,int u,vector<int> &children,vector<int> &visited)
{
    children[u]=1;
    visited[u]=1;
    for(list<int>::iterator it=G.adj[u].begin();it!=G.adj[u].end();++it)
    {
        if(visited[*it]==1)
              continue;
     	children[u]+=calculate_children_nodes(G,*it,children,visited);
    }
    return children[u];
}

int recurse_remove_edges(graph &G,int u,vector<int> &children,vector<int> &visited)
{
	visited[u]=1;
	int ans=0;
    //cout<<endl<<"for vertex :"<<u;
    for(list<int>::iterator it=G.adj[u].begin();it!=G.adj[u].end();++it)
    {
           if(visited[*it]==1)
               continue;
    	   if(children[*it]%2==0)
    	   	    ans+=1+recurse_remove_edges(G,*it,children,visited);
           else
                ans+=recurse_remove_edges(G,*it,children,visited);
    }
    //cout<<"splitting :"<<ans<<" edges for vertex :"<<u<<endl;
    return ans;
}

int remove_edges_form_forest(graph &G)
{
	if(G.n==0)
		 return -1;
	vector<int> children(G.n+1);
    vector<int> child_visited(G.n+1);
    vector<int> edge_visited(G.n+1);
    int k=calculate_children_nodes(G,1,children,child_visited);   
    return recurse_remove_edges(G,1,children,edge_visited);
}

int main()
{
	int n,m;
	n=30;
   // int u[]={2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
  //  int v[]={1,2,3,2,4,4,1,5,4,4,8,2,2,8,10,1,17,18,4,15,20,2,12,21,17,5,27,4,25};

    //m=sizeof(u)/sizeof(u[0]);
    cin>>n>>m;
    graph G(n,m);
    for(int i=0;i<m;i++)
    {
    	int u,v;
    	cin>>u>>v;
        G.add_edge(u,v);
    }
    cout<<remove_edges_form_forest(G);	
}