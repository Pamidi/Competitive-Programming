#include <iostream>
using namespace std;
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string s;
		cin.ignore();
		getline(cin,s);
        int i=0,count=0;
        //add extra 0 in the front and end of string s 'showing no bomb ..so leng(th is s.length()+2;
                string temp="0";
                temp+=s;
                temp+='0';                        //temp indexed from 0..s.length()+1
                for(int i=1;i<=s.length();i++)
                {
                	//start from index 1 to s.length() in temp
                    if(temp[i]=='0'&&temp[i-1]=='0'&&temp[i+1]=='0')
                    	count++;
                }
        cout<<count<<endl;
	}
	return 0;
}