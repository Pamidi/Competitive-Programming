#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <limits.h>

class ChangingSounds
{
public:
	int find_volume(vector<int> &changeintervels,int track,int cur_value,int v_max,vector<vector<int> > &table)
	{
        if(cur_value>v_max || cur_value<0)
        	 return -1;
        if(table[track][cur_value]!=INT_MIN)
        	return table[track][cur_value];
        int ans;
        if(track==changeintervels.size())
             ans=cur_value;
        else
        {
           int t1=find_volume(changeintervels,track+1,cur_value+changeintervels[track],v_max,table);
           int t2=find_volume(changeintervels,track+1,cur_value-changeintervels[track],v_max,table);
           ans=max(t1,t2);
        }
        table[track][cur_value]=ans;
        return ans;
	}
	int maxFinal(vector<int> changeintervels,int begin,int v_max)
	{
		vector<vector<int> > table(changeintervels.size()+1);
		for(int i=0;i<changeintervels.size()+1;i++)
		{
			table[i].resize(v_max+1);
            for(int j=0;j<v_max+1;j++)
            	table[i][j]=INT_MIN;
        }
        int val=find_volume(changeintervels,0,begin,v_max,table);
	    for(int i=0;i<changeintervels.size()+1;i++)
	    {   cout<<endl;
	    	for(int j=0;j<v_max+1;j++)
	    		cout<<table[i][j]<<" ";
	    }
	    return val;
	}
};

int main()
{
	int a[]={5,3,7};
	vector<int> v(a,a+sizeof(a)/sizeof(a[0]));
	int begin=5;
	int end=10;
	ChangingSounds obj;
    cout<<endl<<endl<<obj.maxFinal(v,begin,end)<<endl;
    return 0;
}

