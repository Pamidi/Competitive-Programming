#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>


int main()
{
	string s="ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ";
	int ans=0;
	int i=0;
    for(int i=0;i<s.length();i++)
    {
    	int j=i;
    	ans++;
    	while(j<s.length()&&s[j]==s[i])
    	  j++;
    	i=j-1;
    }
    cout<<ans<<endl;
    return 0;
}