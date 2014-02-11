#include <iostream>
using namespace std;
#include <cstdlib>
#include <algorithm>
#include <vector>

int main()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	int p=a[0];
	vector<int> first,second;
	for(int i=1;i<n;i++)
	{
		if(a[i]<p)
			first.push_back(a[i]);
		else
			second.push_back(a[i]);
	}
	first.push_back(p);
	first.insert(first.end(),second.begin(),second.end());
	for(int i=0;i<n;i++)
		cout<<first[i]<<" ";
	return 0;
}