#include <iostream>
using namespace std;
#include <cstdlib>
#include <algorithm>
#include <string>

int main()
{
	int t;
	cin>>t;
	cin.ignore();
	string onehole="ADOPQR";
	string twohole="B";
	for(int i=0;i<t;i++)
	{
		string s;
		getline(cin,s);
		int holes=0;
		for(int j=0;j<s.length();j++)
		{
			if(onehole.find(s[j])!=string::npos)
		   	holes+=1;
		   else if(twohole.find(s[j])!=string::npos)
		   	holes+=2;
		}
		cout<<holes<<endl;
	}
	return 0;
}