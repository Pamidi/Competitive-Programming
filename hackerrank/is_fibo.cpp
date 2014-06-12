#include <iostream>
using namespace std;
#include <cstdlib>
#include <cmath>
#include <algorithm>

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int n;
		cin>>n;
		long long int test1,test2,root1,root2;
		test1=(5*n*n)-4;
		test2=(5*n*n)+4;
		root1=sqrt(test1);
		root2=sqrt(test2);
		if(root1*root1==test1)
			cout<<"IsFibo";
		else if(root2*root2==test2)
			cout<<"IsFibo";
		else
			cout<<"IsNotFibo";
		cout<<endl;
	}
}