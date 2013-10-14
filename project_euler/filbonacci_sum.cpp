#include<iostream>
using namespace std;
#include<cstdlib>

int main()
{
	long long k,first=0,second=1,third=1,sum=0;
	while(third<=4000000)
	{
		third=first+second;
		if(third%2==0)
		sum+=third;
		first=second;
		second=third;
	}
	cout<<sum;
	return 0;

}