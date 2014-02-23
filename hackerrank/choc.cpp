#include <iostream>
using namespace std;
#include <cstdlib>
#include <algorithm>
#include <vector>

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int n,c,m;
		cin>>n>>c>>m;
		int cur_wrappers=n/c;
		int tot_choc=0;
		while(cur_wrappers>=m)
		{
			cur_wrappers-=m;
			cur_wrappers+=1;
			tot_choc+=m;
		}
		tot_choc+=cur_wrappers;
		cout<<tot_choc<<endl;
	}
}