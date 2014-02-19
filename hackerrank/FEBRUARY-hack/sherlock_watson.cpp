#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>

int main()
{
	int n,k,q;
	cin>>n>>k>>q;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<q;i++)
	{
		int x;
		cin>>x;
		cout<<a[(x-(k%n)+(x-(k%n)<0?n:0))%n]<<endl;
	}
	return 0;
}