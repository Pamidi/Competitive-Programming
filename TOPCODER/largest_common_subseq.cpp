#include <iostream>
using namespace std;
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <string>


int longest(vector<int> &m,vector<int> &n,int t1,int t2,vector<vector<int> > &table)
{ 
    if(t1==0 || t2==0)
    	return 0;
    if(table[t1][t2]!=INT_MIN)
    	return table[t1][t2];
    int ans;
    if(m[t1-1]==n[t2-1])
    	ans=longest(m,n,t1-1,t2-1,table)+1;
    else
    {
     int i=longest(m,n,t1-1,t2,table);
    int j=longest(m,n,t1,t2-1,table);
    int k=longest(m,n,t1-1,t2-1,table);
    ans=max(max(i,j),k);
   }
    table[t1][t2]=ans;
    return ans;
}

int find_longest_sub(vector<int> m,vector<int> n)
{
	vector<vector<int> > table(m.size()+1);
	for(int i=0;i<m.size()+1;i++)
	   table[i].resize(n.size()+1);
	for(int i=0;i<m.size()+1;i++)
	  for(int j=0;j<n.size()+1;j++)
	     table[i][j]=INT_MIN;
	return longest(m,n,m.size(),n.size(),table); 
}

int main()
{
	int a[]={1,2,2,3,5,2,1};
	int b[]={1,2,5,1};
	vector<int> m(a,a+sizeof(a)/sizeof(a[0]));
	vector<int> n(b,b+sizeof(b)/sizeof(b[0]));
	cout<<find_longest_sub(m,n);
}
