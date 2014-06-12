#include <iostream>
using namespace std;
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>

string make_string(int x,int y)
{
	string out="";
	for(int i=0;i<x;i++)
		out+='5';
	for(int i=0;i<y;i++)
		out+='3';
	return out;
}

string find_decent_number(long long int n,int x,int y)
{
	//solve 3x+5y=n;         where x=count(5) and y=count(3)
	if(x+y==n)
		return make_string(x,y);
	if(x+y>n)
		return "-1";
	string out1=find_decent_number(n,x+3,y);
	if(out1!="-1")
		return out1;
	string out2=find_decent_number(n,x,y+5);
	return out2;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int n;
		cin>>n;
		string out=find_decent_number(n,0,0);
        cout<<out<<endl;
	}
}