#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <cstdlib>

int main()
{
	int t,n;
	cin>>n>>t;
	vector<int> width(n);
	for(int i=0;i<n;i++)
		cin>>width[i];
	while(t--)
	{
		int i,j;
		cin>>i>>j;
	    cout<<*min_element(width.begin()+i,width.begin()+j+1)<<endl;
	}
}