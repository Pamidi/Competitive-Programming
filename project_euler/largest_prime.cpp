#include<iostream>
using namespace std;
#include<cstdlib>
#include<cmath>

int main()
{
	long long n=600851475143;
	long long i,j,large=2;
	for(i=sqrt(n);i>=2;i--)
	{
		for(j=2;j<=sqrt(i);j++)
		if(j==sqrt(i))
		{
			cout<<i;exit(0);
		}
	
}
return 0;
}