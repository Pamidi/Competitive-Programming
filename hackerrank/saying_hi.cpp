#include <iostream>
#include <algorithm>
using namespace std;
#include <cstdlib>
#include <vector>
#include <string>

int main()
{
	int n,i;
	cin>>n;
	cin.ignore();
	for(i=0;i<n;i++)
	{
		string s;
		getline(cin,s);
		string output=s;
		transform(s.begin(),s.end(),s.begin(),::tolower);
		if(s.length()<3)
			continue;
		int pos=s.find("hi ");
		if(pos==string::npos||pos!=0)
			continue;
		if(s.length()==3)
			cout<<output<<endl;
		else
			{
				if(s[pos+3]=='d')
					continue;
				else
					cout<<output<<endl;
			}
	}
	return 0;
}