#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <limits.h>

int  main()
{
	long long  n,k,i,temp,j,z,min_value=INT_MAX;;
	vector<long long > candies;
	
	cin>>n>>k;
	for(i=0;i<n;i++)
	{
      cin>>temp;
      candies.push_back(temp);   
	}


    //table[i][j]=minimum unfairness among all j candies from i candies selection
    sort(candies.begin(),candies.end());

	vector<vector<long long > > table;
	vector<vector<long long > > single_diff; 
	table.resize(n);
	single_diff.resize(n);
	for(i=0;i<n;i++)
		{table[i].resize(n);           //make a n*n table with table[i][j] containing modulus sum from i..j sequence
         single_diff[i].resize(n);
        }
    for(i=0;i<n;i++)
    	for(j=0;j<n;j++)
    			{
    			table[i][j]=0;        //initialize
    			single_diff[i][j]=0;
    		    }
    	
	
   //find table in bottom up approach
    for(long long  range=1;range<=n;range++)
    {
    	for(i=0;i<n-range+1;i++)
    	{
    		j=i+range-1;
    		if(range==1)
    			{table[i][j]=0;
    			 single_diff[i][j]=0;
    			}
    		else if(range==2)
    			{
    				table[i][j]=abs(candies[i]-candies[j]);
    				single_diff[i][j]=abs(candies[i]-candies[j]);
    			}
    		else
    		{

    		   temp=0;
    		   for(z=i;z<j;z++)
    		   	 temp+=abs(candies[j]-candies[z]);
    		   single_diff[i][j]=temp;
    		   temp=0;
               temp+=table[i][j-1]+single_diff[i][j];
               table[i][j]=temp;
    		}
    	}
    }
    
    for(i=0;i<=n-k;i++)
    {
       //consider sorted sequence candies[i...i+k-1]
         min_value=min(min_value,table[i][i+k-1]); 
         
    }

    cout<<min_value;
    return 0;
}