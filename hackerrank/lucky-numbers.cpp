#include <iostream>
using namespace std;
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <math.h>

const int prime_max=1601;

int main()
{
	unordered_map<int,bool> is_prime;
	int i,j;
	for(i=0;i<1601;i++)
		is_prime[i]=true;
	
    for(i=2;i<=sqrt(prime_max);i++)
	{
		if(is_prime[i])
		{
			for(j=i*i;j<=prime_max;j+=i)
				is_prime[j]=false;
		}
	}
    
    exit(0);
    unordered_map<long long int,long long int> table;        //storing lucky number till value i
    long long int k=pow(10,18);
    for(i=0;i<=k;i++)
    	table[i]=0;
    for(i=1;i<=k;i++)
    {
    	int check=0;
    	int temp=i;
    	int sum=0;
    	while(temp>0)
    	{
    		int last=temp%10;
    		sum+=last*last;
    		last=last/10;
    	}
        if(is_prime[sum])
        	check=1;
    	table[i]=table[i-1]+check;
    }

    int t;
    cin>>t;
    for(i=0;i<t;i++)
	{
		long long int a,b;
		cin>>a>>b;
        int j;
        cout<<table[b]-table[a]+1<<endl;
	}
}