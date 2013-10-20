#include <iostream>
using namespace std;
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <numeric>

int main()
{
	int N,i,prev_candy=0,prev_rat=0,val;
	vector<int> rating;
	vector<int> candy;       //candy for each;
	cin>>N;
	for(i=0;i<N;i++)
	{
        cin>>val;
        rating.push_back(val);
        if(val>prev_rat)
        {
        prev_candy=prev_candy+1;
        candy.push_back(prev_candy);
        }
        else
        {
        	if(prev_candy==1)               //increment
        	{   int j=i;
        		prev_candy=1;
        		candy.push_back(1);
                while(j>=0&&rating[j]<rating[j-1]&&candy[j]&&candy[j]>=candy[j-1])
                {
                	candy[j-1]+=1;
                	j--;
                }
        	}
        	else
        	{
        		prev_candy=1;
        		candy.push_back(1);
        	}

        }
        prev_rat=val;
	}
	cout<<accumulate(candy.begin(),candy.end(),0);;
return 0;
}