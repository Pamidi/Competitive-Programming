#include <iostream>
using namespace std;
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#include <numeric>


struct node
{
	bool visited;
	node()
	{
		visited=false;
	}
};

struct graph
{
    int v;
    vector<int>* adj;
    vector<node> vertex;
    graph(int d)
    {
          v=d;
          adj=new vector<int>[v];        //reserve
          vertex.reserve(v);
          for(int i=0;i<v;i++)
          {
            vertex[i].visited=false;
          	adj[i].reserve(v);
          }
          for(int i=0;i<v;i++)
          	for(int j=0;j<v;j++)
          		adj[i][j]=0;
    }
    void add_edge(int u,int v,int len)
    {
    	adj[u][v]=len;
    	adj[v][u]=len;
    }
};

int find_max_depth(graph &g,int s)
{
	g.vertex[s].visited=true;
	int max_depth=0;;
    for(int i=0;i<g.v;i++)
    {   
    	if(g.adj[s][i]!=0&&!g.vertex[i].visited)
    		max_depth=max(max_depth,g.adj[s][i]+find_max_depth(g,i));
    }
    return max_depth;
}

int estimateTimeOut(vector<int> fromJunction,vector<int> toJunction,vector<int> ductLength)
{
   int k=max(*max_element(fromJunction.begin(),fromJunction.end()),*max_element(toJunction.begin(),toJunction.end()));	
   graph g(k+1);         //4 vertices.
   for(int i=0;i<fromJunction.size();i++)
     	g.add_edge(fromJunction[i],toJunction[i],ductLength[i]);
   int tot_time=2*accumulate(ductLength.begin(),ductLength.end(),0);
   return tot_time-find_max_depth(g,0);
}

int main()
{
   int a[]={0,1,0};
   int b[]={1,2,3};
   int c[]={10,10,10};
   vector<int> fromJunction,toJunction,ductLength;
   fromJunction.assign(a,a+sizeof(a)/sizeof(a[0]));
   toJunction.assign(b,b+sizeof(b)/sizeof(b[0]));
   ductLength.assign(c,c+sizeof(c)/sizeof(c[0]));
   cout<<estimateTimeOut(fromJunction,toJunction,ductLength)<<endl;
   return 0;
}