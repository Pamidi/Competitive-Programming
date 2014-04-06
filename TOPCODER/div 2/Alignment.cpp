#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <string>

class Alignment
{
	int x;
public:
	int find_minimum_cost(string &a,string &b,int a_track,int b_track,int cost,bool b_dash_first,bool a_dash_first)
	{
    cout<<"a_track:"<<a_track<<endl<<"b_track:"<<b_track<<endl<<"b_dash_first:"<<b_dash_first<<endl<<"a_dash_first"<<a_dash_first<<endl<<"cost:"<<cost<<endl<<endl;;
		if(a_track==a.length()&&b_track==b.length())
       	   return cost;
       if(a_track==a.length())
       {
       	  //simply add _ for all remaining b symbols
       	  return cost+(b.length()-b_track)+(!a_dash_first?x:0);
       }
       if(b_track==b.length())
       {
       	  //simply add _ for all remaining a symbols
       	  return cost+(a.length()-a_track)+(!b_dash_first?x:0);
       }
       //general case when not equal...try both cases and find maximum by inserting - in both strings
       bool store_b=b_dash_first;
       b_dash_first=(!b_dash_first)?true:false;
       int first=find_minimum_cost(a,b,a_track+1,b_track,cost+1+(b_dash_first?x:0),b_dash_first,a_dash_first);
       b_dash_first=store_b;
       cout<<"first:"<<first<<endl;

       bool store_a=a_dash_first;
       a_dash_first=(!a_dash_first)?true:false;
       int second=find_minimum_cost(a,b,a_track,b_track+1,cost+1+(a_dash_first?x:0),b_dash_first,a_dash_first);
       a_dash_first=store_a;
       cout<<"second:"<<second<<endl;
       first=min(first,second);
       first=min(first,a[a_track]==b[b_track]?find_minimum_cost(a,b,a_track+1,b_track+1,cost,false,false):INT_MAX);
       return first;
	}
	int align(string a,string b,int x)
	{
		this->x=x;
		return find_minimum_cost(a,b,0,0,0,false,false);
	}
};

int main()
{
	Alignment obj;
    string a="AAABAAAABAA";
    string b="AAAABAABAAA";
    cout<<obj.align(a,b,1);
    return 0;
}