#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <limits.h>
#include <string>

class ColorfulRoad
{
public:
	  char get_next_color(char cur)
	  {
	  	if(cur=='R') return 'G';
	  	if(cur=='G') return 'B';
	  	if(cur=='B') return 'R';
	  }
	  int getMin(string road)
	  {
          vector<int> table(road.length());
          for(int j=0;j<road.length();j++)
          			table[j]=INT_MAX;
          table[road.length()-1]=0;
          for(int j=road.length()-2;j>=0;j--)
          { 
          	bool no_path=true;
            for(int i=j+1;i<road.length();i++)
          	{
          		//jump from j to i
                if(road[i]==get_next_color(road[j]))
                {
                   if(table[i]!=-1)
                   {
          		      table[j]=min(table[j],((i-j)*(i-j))+table[i]);
          		      no_path=false;
          		   }
          		}
          	}
          	if(no_path)
          		table[j]=-1;
          }
         return table[0];
      }
};

int main()
{
	 ColorfulRoad obj;
	 cout<<obj.getMin("RBBGGGRR");
	 return 0;
}
