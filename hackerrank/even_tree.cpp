#include <iostream>
using namespace std;
#include <cstdlib>
#include <vector>
#include <algorithm>

struct node
{
	int children;
	bool visited;
	node()
	{
		children=0;
		visited=false;
	}
};

struct graph
{
    int v;           				//number of vertices
    int e;							//number of edges
    vector<node> vertex;            //all vertex
    vector<int> *adj;	    //adjacency matrix 
    graph(int d,int k)
    {
         v=d;
         e=k;
         adj=new vector<int>[v];
         vertex.reserve(v);
         for(int i=0;i<v;i++)
         {
         	vertex[i].children=0;   //setting children to 0 initially
         	vertex[i].visited=false;
         }
    }
    void addEdge(int u,int v)      //add an edge (u,v) and (v,u)
    {
         adj[u-1].push_back(v-1);
         adj[v-1].push_back(u-1);
    }
};

int find_connected_members(graph &g,int s)  //find children for vertex s
{
    g.vertex[s].children+=1;                 //adding the source vertex also
    g.vertex[s].visited=true;
	//cout<<"at vertex:"<<s<<endl;
	for(int i=0;i<g.adj[s].size();i++)
	{
	//	cout<<"considering neighbour "<<g.adj[s][i]<<endl;
		if(!g.vertex[g.adj[s][i]].visited) //for each edge (s,i) and i not visited before
		{
	//		cout<<"calling function with neighbour"<<g.adj[s][i]<<endl;
			g.vertex[s].children+=find_connected_members(g,g.adj[s][i]);
		}
	}
	//cout<<" vertex "<<s<<" : "<<g.vertex[s].children<<endl;
	return g.vertex[s].children;
}

int start_breaking_at(graph &g,int s)
{
   if(g.vertex[s].children%2==1)    //cant be broken further
      return 0;
   int tot_break=0;
   int k=g.adj[s].size();
   int count=0;
   for(int i=0;i<k;i++)
   {
   	   int neighbour=g.adj[s][count];
       if(g.vertex[neighbour].children%2==0)
       {
         //remove element
         auto it=find(g.adj[s].begin(),g.adj[s].end(),neighbour);
       	 g.adj[s].erase(it);
       	 it=find(g.adj[neighbour].begin(),g.adj[neighbour].end(),s);
       	 g.adj[neighbour].erase(it);
       	 tot_break++;
       	 tot_break+=start_breaking_at(g,neighbour);
       }
       else
       	count++;
   }
  return tot_break;
}

int make_max_connected_components(graph &g)
{
     int c=find_connected_members(g,0);
  //   cout<<c<<endl;
     if(c%2==1)                              //cant break further
     	return 0; 
     return start_breaking_at(g,0);
}

int main()
{
    int n,m;
    cin>>n>>m;
    graph g(n,m);
    for(int i=0;i<m;i++)
    {
       int u,v;
       cin>>u>>v;
       g.addEdge(u,v);
    }
    cout<<make_max_connected_components(g)<<endl;
}