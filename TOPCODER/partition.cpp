#include <iostream>
using namespace std;
#include <algorithm>
#include <cstdlib>
#include <vector>

int partition(int n,vector<int> &table,int start)
{
	if (n==1||n==0)
		return 1;
    if(table[n]!=INT_MIN)
    	 return table[n];
	int res=0;
	for(int i=start;i<n;i++)
       res+=partition(n-i,table,i);
   table[n][start]=res;
   return table[n][start];
}

int main()
{
   int n=10;
   vector<vector<int> > table(n+1);
   for(int i=0;i<n+1;i++)
      table[i].resize(n+1);
   for(int i=0;i<n+1;i++)
   	   table[i]=INT_MIN;
   table[0]=1;
   table[1]=1;
   cout<<partition(n,table,1)<<endl;
}