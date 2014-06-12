#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <map>

typedef long long int lli;

int main()
{
	lli n,m,i;
	cin>>n;
	vector<int> a(n);
	map<int,int> map_a;
    for(i=0;i<n;i++)
    	cin>>a[i];
    cin>>m;
    vector<int> b(m);
    vector<int> output;
    map<int,int> map_b;
    for(i=0;i<m;i++)
    	cin>>b[i];
    for(i=0;i<n;i++)
    	map_a[a[i]]++;
    for(i=0;i<m;i++)
    	map_b[b[i]]++;
    for(i=0;i<m;i++)
    {
    	if(map_b[b[i]]>map_a[b[i]])
        	output.push_back(b[i]);
    	map_b[b[i]]=0;
    }
    sort(output.begin(),output.end());
    for(i=0;i<output;i++)
    	cout<<output[i]<<" ";

}