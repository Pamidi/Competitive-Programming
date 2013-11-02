#include <iostream>
using namespace std;
#include <cstdlib>
#include <algorithm>
#include <vector>

int main()
{
	int t,i;
	cin>>t;
	for(i=0;i<t;i++)
	{
		int n,k;
		cin>>n;
		vector<int> input(n);
		for(int j=0;j<n;j++)
            cin>>input[j];
        cin>>k;
        int val=input[k-1];
        int count_front=0;
        for(int j=0;j<n;j++)
        {
        	if(input[j]<val)
        		count_front++;
        	else if(input[j]==val&&(j<(k-1)))
        		count_front++;
        }
        count_front++;
        cout<<count_front<<endl;
	}
	return 0;
}