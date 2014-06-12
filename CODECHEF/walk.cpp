#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <limits.h>

typedef long long int lli;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		lli n;
		cin>>n;
		vector<lli> w(n);
		for(lli i=0;i<n;i++)
		    cin>>w[i];
		lli index,max_value=LLONG_MIN;
		for(lli i=0;i<n;i++)
		{
			 if(w[i]>max_value)
			 {
			 	max_value=w[i];
			 	index=i;
			 }
		}
        
        lli start_velocity=max_value+index;
        lli cur_velocity=max_value;
        for(lli i=index;i<n;i++)
        {
        	if(cur_velocity<w[i])
        	{
        		start_velocity+=w[i]-cur_velocity;
        		cur_velocity=w[i];
        	}
        	cur_velocity--;
        }
       cout<<start_velocity<<endl;
	}
	return 0;
}