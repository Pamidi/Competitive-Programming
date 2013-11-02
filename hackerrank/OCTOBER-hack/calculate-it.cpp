#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
#include <limits.h>
#include <vector>

long long int hrank(long long int x,long long int k,vector<long long int> &table)
{
   if(table[x]!=LLONG_MAX)
   	 return table[x];

   if(0<=x&&x<k)
   	 table[x]=1;

   else if (x>=k&&(x%k==0))
   	 table[x]=hrank(x-k,k,table)+hrank(x/k,k,table);

   else
   	 table[x]=hrank(x-1,k,table);

   return table[x];
}

int main()
{
	long long int k;
	long long int x;
	cin>>k>>x;
	vector<<vector<long long int> table;
	table.resize(x+1,LLONG_MAX);
	table[0]=1;
	cout<<hrank(x,k,table)<<endl;
  return 0;
} 