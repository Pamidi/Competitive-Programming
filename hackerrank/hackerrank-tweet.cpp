#include <iostream>
using namespace std;
#include <algorithm>
#include <string>
#include <cstdlib>

int main()
{
	int n,i;
	cin>>n;
	cin.ignore();
	int count=0;
	for(i=0;i<n;i++)
	{
		string s;
		getline(cin,s);
		string out=s;
		transform(s.begin(),s.end(),s.begin(),::tolower);
		int pos=s.find("hackerrank");
		if(pos==string::npos)
			continue;
		count++;
	}
	cout<<count<<endl;
	return 0;
}