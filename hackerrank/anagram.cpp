#include <iostream>
using namespace std;
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <climits>
#include <unordered_map>

typedef unordered_map<int,int> char_map;

int main()
{
	int t;
	cin>>t;
	cin.ignore();
	while(t--)
	{
		string a,b,in;
		int char_mod=0;
		getline(cin,in);
	    if(in.length()%2==1)
	    	cout<<"-1"<<endl;
	    else
	    {
	    	a=in.substr(0,in.length()/2);
	    	b=in.substr(in.length()/2,in.length()/2);
	    	char_map a_map,b_map;
	    	for(int i=0;i<26;i++)
	    		a_map[i]=b_map[i]=0;
	    	for(int i=0;i<a.length();i++)
	    	{
	    		a_map[a[i]-97]++;
                b_map[b[i]-97]++;
            }
            for(int i=0;i<26;i++)
            {
            	if(a_map[i]>b_map[i])
            		char_mod+=a_map[i]-b_map[i];
            }
            cout<<char_mod<<endl;
	    }
	}
return 0;
}
