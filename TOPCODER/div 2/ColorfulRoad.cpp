#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <cstdlib>

class ColorfulRoad
{
	string road;
    vector<int> c;
public:
	bool is_color(int x,int i)
	{
	    if(road[x-1]=='G'&&road[i-1]=='R') return true;
	    if(road[x-1]=='B'&&road[i-1]=='G') return true;
	    if(road[x-1]=='R'&&road[i-1]=='B') return true;
	    return false;
	}
	int find_min(int x,int cost)
	{
	//	cout<<"x:"<<x<<endl<<"initial cost:"<<c[x]<<endl<<endl;
        if(c[x]!=INT_MAX)           //if not calculated before
            return c[x];
		if(x==1) return cost;
		bool no_prec_color=true;
		int ans=INT_MAX;
		for(int i=x-1;i>=1;i--)
		{
           if(is_color(x,i))
           {
           	 c[x]=min(c[x],find_min(i,cost+(x-i)*(x-i)));
           	 no_prec_color=false;
		   }
		}
		if(no_prec_color)
			c[x]=INT_MAX;
	//	cout<<"returning :"<<c[x]<<" for x:"<<x<<endl;
        return c[x];
	}
	int getMin(string road)
	{
       this->road=road;
       c.resize(road.length()+1);
       fill(c.begin(),c.end(),INT_MAX);
       c[road.length()]=find_min(road.length(),0);
       return c[road.length()];
	}
};

int main()
{
   string road="RBBGGGRR";
   ColorfulRoad obj;
   if(obj.getMin(road)!=INT_MAX)
   	  cout<<obj.getMin(road);
   else
   	  cout<<"-1"<<endl;
   return 0;
}