#include <iostream>
using namespace std;
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

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
		sort(w.begin(),w.end());
	    int diff=0;
	    if(n==1)
	    	cout<<"1"<<diff<<endl;
	    

	}
}