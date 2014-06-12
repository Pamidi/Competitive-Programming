#include <iostream>
using namespace std;
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

int main()
{
	long long int n,m;
	cin>>n>>m;
	long long int sum=0;
	for(int i=0;i<m;i++)
	{
		long long int a,b,k;
		cin>>a>>b>>k;
		sum+=(b-a+1)*k;
	}
	cout<<sum/n<<endl;
} 