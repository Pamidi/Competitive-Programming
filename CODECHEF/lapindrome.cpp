#include<iostream>
using namespace std;
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<sstream>
#include<algorithm>

string check_lapindrome(string a)
{
  string st1,st2;
	st1=a.substr(0,a.length()/2);
	st2=a.substr((a.length()/2)+(a.length()%2));
	if(st1.length()!=st2.length())
		return "NO";
    for(int i=0;i<st1.length();i++)
    {
    	int x=count(st2.begin(),st2.end(),st1[i]);
    	int y=count(st1.begin(),st1.end(),st1[i]);
        if(x!=y)
        	return "NO";
    }
	return "YES";
}

int main()
{
	int t,i;
	cin>>t;
    cin.ignore();
	string a,res[t];
	for(i=0;i<t;i++)
	{
	 getline(cin,a);
	 res[i]=check_lapindrome(a);
	}

	for(i=0;i<t;i++)
	cout<<res[i]<<"\n";
	return 0;
}
