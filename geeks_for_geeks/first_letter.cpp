#include <iostream>
using namespace std;
#include <string>
#include <algorithm>

int main()
{
	string s;
	getline(cin,s);
	int i;
	int k=0;
	while(k<s.length())
	{
		if(s[k]==' ')
			{k++;
			continue;
		    }
		else
			{cout<<s[k];
             while(k!=s.length()&&s[k]!=' ')
             	k++;
             continue;
            }
   }
return 0;
}