#include <iostream>
using namespace std;
#include <string>
#include <cstdlib>
#include <algorithm>
#include <vector>

int main()
{
	int n,i;
	vector<string> data;
	cin>>n;
	cin.ignore();
	for(i=0;i<n;i++)
	{
	   string temp;
	   getline(cin,temp);
	   data.push_back(temp);
	}
	int t;
	cin>>t;
	cin.ignore();
	for(i=0;i<t;i++)
	{
		string w,temp;
		getline(cin,w);
        temp=w;
        temp[w.length()-2]='s';
        int count=0;
        for(int j=0;j<n;j++)
        {
        	int pos=data[j].find(w,0);
        	while(pos!=string::npos)
            {
            	count++;
            	pos=data[j].find(w,pos+1);
            }
        	pos=data[j].find(temp,0);
        	while(pos!=string::npos)
            {
            	count++;
            	pos=data[j].find(temp,pos+1);
            }
        }
        cout<<count<<endl;;

	}
}