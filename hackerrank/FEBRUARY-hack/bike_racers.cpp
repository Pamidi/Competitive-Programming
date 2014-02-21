#include <iostream>
using namespace std;
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <limits.h>

typedef long long int LLI;
int n,m,k;

     
struct biker
{
   LLI x;
   LLI y;
   bool race_member;
   bool visited;
   biker(LLI p,LLI q)
   {
   	 race_member=false;
   	 visited=false;
   	 x=p;
   	 y=q;
   }
};

struct bike
{
   LLI x;
   LLI y;
   bool race_member;
   bike(LLI p,LLI q)
   {
   	race_member=false;
   	x=p;
   	y=q;
   }
};

class Graph
{
    int V;    // No. of vertices
    vector<int> *adj;    // Pointer to an array containing adjacency lists
 public:
    Graph(int V);  // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    void BFS(int s);  // prints BFS traversal from a given source s
    void show_adj();
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new vector<int>[V];   
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::show_adj()
{
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<adj[i].size();j++)
			cout<<adj[i][j]<<" ";
		cout<<endl;
	}
}
LLI start_dfs_at(Graph &g,vector<bike> total_bikes,vector<biker> total_bikers,int s,int pick)                  //pick is number of race bikes selected so far..
{	
	bool is_biker=false;
	if(s<n)
		is_biker=true;
	LLI min_value=LLONG_MAX;
   // cout<<endl<<" start_dfs_at vertex"<<s<<endl;
   // cout<<"current selection:"<<pick<<endl;
	
    if(!is_biker)           //if s is a bike,simply call dfs with all other vertices
    {
  //  	cout<<"it is bike:"<<s<<endl;
    	for(int i=0;i<n;i++)
        {
          if(!total_bikers[i].race_member)
          {
            LLI temp=start_dfs_at(g,total_bikes,total_bikers,i,pick);		
            min_value=min(min_value,temp);
          }
        }
 //       cout<<"returning "<<min_value<<endl<<endl;
        return min_value;
    }
    else                   //if s is a biker,choose a bike i.e reserver biker and bike
    {
        if(total_bikers[s].visited)
            return LLONG_MAX;  
    	total_bikers[s].visited=true;
 //   	cout<<"it is  biker:"<<s<<endl;
    	 for(int i=0;i<m+1;i++)      //choose one bike or no bike
        {
        	LLI cur_time=0;
        	if(i==m)                //not choosing that biker
        	{
   //     		cout<<"CHOOSING NO BIKE"<<endl;
        		total_bikers[s].race_member=false;
        	}
        	else
        	{
        	  if(total_bikes[i].race_member)
        	  {
   //     	  	cout<<"BIKE AT INDEX :"<<i+n<<" ALREADY CHOSEN"<<endl;
        	  	continue;
        	  }
        	  total_bikers[s].race_member=true;
   //     	  cout<<"CHOOSING BIKE AT INDEX:"<<i+n<<endl;
        	  cur_time=abs(total_bikes[i].y-total_bikers[s].y)+abs(total_bikes[i].x-total_bikers[s].x);
   //       	  cout<<"cur_time:"<<cur_time<<endl;
        	  if(pick+1==k)        //selection complete and next bike is not chosen already
        	  {
  //      	  	cout<<"SELECTION COMPLETE.."<<endl;
        	  	min_value=min(min_value,cur_time);
        	  	total_bikers[s].race_member=false;
        	  	continue;
        	  }
        	  total_bikes[i].race_member=true;
        	} 
        	if(i==m)
        		min_value=min(min_value,max(cur_time,start_dfs_at(g,total_bikes,total_bikers,i+n,pick)));
        	else
        	    min_value=min(min_value,max(cur_time,start_dfs_at(g,total_bikes,total_bikers,i+n,pick+1)));
    //    	cout<<"CURRENT MIN_VALUE:"<<min_value<<endl;
        	total_bikes[i].race_member=false;
        	total_bikers[s].race_member=false;
        }
    }
  //  cout<<endl;
 return min_value;
}

int main()
{
   vector<biker> total_bikers;
   vector<bike> total_bikes; 
   
   cin>>n>>m>>k;
   for(int i=0;i<n;i++)						//n is number of bikers
   {
   	 LLI x,y;
   	 cin>>x>>y;
     biker p(x,y);
   	 total_bikers.push_back(p);
   }
   for(int i=0;i<m;i++)					   //m is number of bikes
   {
   	 LLI x,y;
   	 cin>>x>>y;
   	 bike p(x,y);
   	 total_bikes.push_back(p);	
   }

   Graph g(m+n+1);

   for(int i=0;i<n;i++)               //all bikers
   {  
   	  for(int j=0;j<m;j++)				//all bikes with index j+n
   	  {
         g.addEdge(i,j+n);
         g.addEdge(j+n,i);
      }
      g.addEdge(i,m+n);              // to not choose that biker
      g.addEdge(m+n,i);
   }

   //graph created.
   LLI out_time;
   out_time=start_dfs_at(g,total_bikes,total_bikers,0,0);	
   cout<<out_time*out_time<<endl;
   return 0;
}