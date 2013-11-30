#include <iostream>
using namespace std;
#include <cstdlib>
#include <algorithm>
#include <vector>

int N,X,ans=0;

void find_max_profit(vector<int> v,vector<int> a,int sum,int index,int profit)
{
	//cout<<"sum:"<<sum<<endl;
	//cout<<"ans:"<<ans<<endl;
	//cout<<"N:"<<N<<endl;
     if(sum==0)
     {    if(profit>ans)
         	ans=profit;
         	return;
     }
     if(index==N)
         return;
     else
     	{

     	find_max_profit(v,a,sum-a[index],index+1,profit+v[index]);
        find_max_profit(v,a,sum,index+1,profit);
        }
}

int main()
{
	int m,n;;
	cin>>N>>X;
	int i;
	vector<int> v,a;
	for(i=0;i<N;i++)
	{
       cin>>m>>n;
       v.push_back(m);
       a.push_back(n);
	}
    find_max_profit(v,a,X,0,0);
    if(ans==0)
    	cout<<"Got caught!";
    else
    	cout<<ans<<endl;
    return 0;
}