#include <iostream>
using namespace std;
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <limits.h>

class ShorterSuperSum
{
public:
	int supersum(int k,int n,vector<vector<int> > &table)
	{
		if(table[k][n]!=INT_MAX)
			return table[k][n];
		int ans=0;
		if(k==0)
			ans=n;
		else
		{
           for(int i=0;i<n;i++)
           	  ans+=supersum(k-1,i+1,table);
		}
		table[k][n]=ans;
		return ans;
	}
	int calcualate(int k,int n)
	{
	   vector<vector<int> > table(k+1);
	   for(int i=0;i<k+1;i++)
	   	  table[i].resize(n+1);
	   for(int i=0;i<k+1;i++)
	   	for(int j=0;j<n+1;j++)
	   		table[i][j]=INT_MAX;
       return supersum(k,n,table);
	}
};

int main()
{
  ShorterSuperSum obj;
  cout<<obj.calcualate(1,3)<<endl;
  return 0;
}