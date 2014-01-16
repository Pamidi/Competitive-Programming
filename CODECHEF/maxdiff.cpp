#include <iostream>
using namespace std;
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <numeric>
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>n>>k;
		vector<int> w(n);
		for(int i=0;i<n;i++)
			cin>>w[i];
		sort(w.begin(),w.end());
        int t1=accumulate(w.begin()+k,w.end(),0)-accumulate(w.begin(),w.begin()+k,0);
        int t2=accumulate(w.begin()+n-k,w.end(),0)-accumulate(w.begin(),w.begin()+n-k,0);
        cout<<max(t1,t2)<<endl;
	}
	return 0;
}