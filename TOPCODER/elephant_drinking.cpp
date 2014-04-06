#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <unordered_map>

struct point
{
	int x;
	int y;
};

class ElephantDrinking
{
public:
	int maxSum(vector<string>);
};

int drinking_water(vector<int> &config,vector<string> &field,int track,int &best)
{
	//we have a configuration here now in config
    unordered_map<point,int> water;
    for(int i=0;i<field.size();i++)
    {
    	for(int j=0;j<field.size();j++)
    	{
    		point temp;
    		temp.x=i; temp.y=j;
            if(field[i][j]=='Y')
            	water[temp]=1;
    	}
    }
	

    bool flag=true,out_flag=true;
    int el_count=0;
	for(int i=0;i<config.size();i++)
	{
		//each elephant
		if(config[i]==0)
			continue;
		count++;
		int index;
        if((i<n)||(i>=2*n&&i<3*n))
		{
             bool top=(i<n)?true:false;
             index=(i<n)?i:n-1-(i-2*n);
             for(int j=(top?0:n-1);(top?j<n:j>=0);(top?j++:j--))
             {
                point temp;
                temp.x=i;temp.y=j;
                if(water[temp]==1)
                	 water[temp]=2;   //occupied slot
                else if(water[temp]==2)
                	{ 
                	  flag=false;
                	  break;
                    }
             } 
		}
		else
		{
            bool left=(i>3*n-1)?true:false;
            index=(i>3*n-1)?n-1-(i-3*n):2*n-i;
            for(int j=(left?0:n-1):(left?j<n:j>=0);(left?j++:j--))
            {
            	point temp;
            	temp.x=i; temp.y=j;
            	if(water[temp]==1)
            		water[temp]=2;
            	else if(water[temp]==2)
            	{
            		flag=false;
            		break;
            	}
            }
		}

        if(!flag)
        {
            out_flag=false;
	    	break;
	    }
	}

	if(out_flag)
    	best=max(best,count);
    
    //we have set the best for the current configuration
    config[track]=0;
    best=max(best,drinking_water(config,field,track-1,best));
    config[track]=1;
    best=max(best,drinking_water(config,field,track-1,best));   
    
  return best;
}

int ElephantDrinking::maxSum(vector<string> field)
{
    int n=field.size();
    //field is n*n matrix
    vector<int> config(4*n);  
    //initial config 0.000 (4n times)
    int best=INT_MIN;
    best=max(best,drinking_water(config,field,4*n-1,best));
}

int main()
{
	ElephantDrinking obj;
	char* p[]={"00000", "00110","01000", "00100", "00000"};
	vector<string> field(p,p+sizeof(p)/sizeof(p[0]));
	cout<<obj.maxSum(field)<<endl;
	return 0;
}