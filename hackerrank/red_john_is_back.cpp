#include <iostream>
using namespace std;
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <limits.h>
#include <cmath>

int find_ways(vector<vector<int> > &c,int m,int n)         // m=4 and n is length
{
	if(c[m][n]!=INT_MIN)
		return c[m][n];
	if(n<=0)
		return 0;
	if(n==4)
		c[m][n]=2;
	else if(n<4)
		c[m][n]=1;
	else
		c[m][n]=find_ways(c,m,n-1)+find_ways(c,m,n-m);
    return c[m][n];
}

int find_primes_less_than(int p)
{
	vector<int> sieve(p+1);
	for(int i=0;i<p;i++)
		sieve[i]=0;
	sieve[0]=1;sieve[1]=1;
	int prime_count=0;
	for(int i=2;i<=sqrt(p);i++)
	{
		for(int j=2*i;j<=p;j+=i)
		{
			sieve[j]=1;
		}
	}
	for(int i=2;i<=p;i++)
		if(sieve[i]==0)
			prime_count++;
    return prime_count;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<vector<int> > c(5);          //of dimension 4*n;
		for(int i=0;i<=4;i++)
			for(int j=0;j<=n;j++)
			  c[i].push_back(INT_MIN);
		int ways=find_ways(c,4,n);	
        cout<<find_primes_less_than(ways)<<endl;
	}
}