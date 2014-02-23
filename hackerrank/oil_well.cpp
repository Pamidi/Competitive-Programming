#include <iostream>
using namespace std;
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <climits>

struct well
{
	int x;
	int y;
};

int main()
{
	int r,c;
	cin>>r>>c;
	int field[r][c];
	for(int i=0;i<r;i++)
	{
      for(int j=0;j<c;j++)
      	cin>>field[i][j];
	}
	int min_cost=0;
	bool first_well=true;
	well last_well;
	for(int i=0;i<r;i++)
	{
		if(i%2==0)
		{
			//read from left to right
			for(int j=0;j<c;j++)
			{
               if(field[i][j]==1)
               {
               	if(first_well)
               	 first_well=false;
               	else
               	 min_cost+=max(abs(j+1-last_well.y),abs(i+1-last_well.x));
               	last_well.x=i+1;
               	last_well.y=j+1;
               }

			}
		}
		else
		{
			//read from right to left
		    for(int j=c-1;j>=0;j--)
		    {
               if(field[i][j]==1)
               {
               	if(first_well)
               		first_well=false;
               	else
               	 min_cost+=max(abs(j+1-last_well.y),abs(i+1-last_well.x));
               	last_well.x=i+1;
               	last_well.y=j+1;
               }
		    }
		}

	}
	 cout<<min_cost<<endl;
}