#include <iostream>
using namespace std;
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <string>

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int g;
		cin>>g;
		while(g--)
		{
			long long int n;
			int i,q;
			cin>>i>>n>>q;
			//assume i and q doesnt matter...i.e head-head and tail-tail are equivalent
			//apparently after playing n round,n/2 coins with have same initial face,
			int same_face=n/2;
			if(i==q)
				cout<<same_face<<endl;
			else
				cout<<n-same_face<<endl;
		}
	}
	return 0;
}