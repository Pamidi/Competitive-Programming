#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <unordered_map>

int main()
{
	int n;
	cin>>n;
	cin.ignore();
	unordered_map<char,int> table;
	while(n--)
	{
		string s;
		getline(cin,s);
		for(int i=0;i<s.length();i++)
			table[s[i]]++;
	}
	int count=0;
	for(i=0;i<26;i++)
	{
		if(table[97+i]!=0)
			count++;
	}
	cout<<count<<endl;
	return 0;
}
