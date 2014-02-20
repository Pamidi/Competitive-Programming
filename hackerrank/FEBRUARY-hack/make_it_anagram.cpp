#include <iostream>
using namespace std;
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <unordered_map>

typedef unordered_map<int,int> char_map;

int main()
{
	string a,b;
	int i,char_remove=0;
	getline(cin,a);
	getline(cin,b);

	char_map a_map,b_map;
	for(i=0;i<26;i++)
	  a_map[i]=b_map[i]=0;	
	for(i=0;i<a.length();i++)
		a_map[a[i]-97]++;
	for(i=0;i<b.length();i++)
		b_map[b[i]-97]++;
	for(i=0;i<26;i++)
	   	char_remove+=max(a_map[i],b_map[i])-min(a_map[i],b_map[i]);
	cout<<char_remove<<endl;
    return 0;
}