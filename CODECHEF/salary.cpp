#include <iostream>
using namespace std;
#include <cstdlib>
#include <vector>
#include <algorithm>

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> w(n);
		for(int i=0;i<n;i++)
			cin>>w[i];
		int ans=0;
		int min=*min_element(w.begin(),w.end());
		for(int i=0;i<n;i++)
			ans+=w[i]-min;
		cout<<ans<<endl;
	}
	return 0;
}