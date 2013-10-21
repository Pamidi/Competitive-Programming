#include <iostream>
using namespace std;
#include <algorithm>

int main()
{
	int t;
	cin>>t;
	int v[1000002];
	int temp;
	for(int i=0;i<t;i++)
      {
          cin>>v[i];
      }
    sort(v,v+t);
    for(int i=0;i<t;i++)
    	cout<<v[i]<<endl;
    return 0;
}