#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <cmath>

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int k;
		cin>>k;
		if(k%2==0)
			cout<<(k/2)*(k/2);
		else
			cout<<(k/2)*((k/2)+1);
		cout<<endl;
	}
}