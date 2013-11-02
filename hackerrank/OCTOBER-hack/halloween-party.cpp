#include <iostream>
using namespace std;
#include <cstdlib>
#include <vector>


int main()
{
	long long int t,i;
	cin>>t;
	for(i=0;i<t;i++)
	{
       long long int k;
       cin>>k;
       if(k%2==0)
       	 cout<<(k/2)*(k/2)<<endl;
       	else
       		cout<<((k+1)/2)*((k-1)/2)<<endl;
	}
	return 0;
}