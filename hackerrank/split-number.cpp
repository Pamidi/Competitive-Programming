#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>

int main()
{
	int n,i;
	cin>>n;
	for(i=0;i<n;i++)
	{
       string code;

       getline(cin,code);
       int pos_space=code.find(" ");
       int pos_hiphen=c
       code.find("-");
       int pos;
       string sep_char;
       if(pos_space==string::npos)
           {
           	pos=pos_hiphen;
           	sep_char="-";
           }
       if(pos_hiphen==string::npos)
           {
           	sep_char=" ";
            pos=pos_space;
           }
       vector<string> segments;
       vector<int> positions;
       string temp;
       while(pos!=string::npos)
       {
          positions.push_back(pos);
          pos=code.find(sepchar);
       }    
       int start=0;
       for(int j=0;j<2;j++)
       {
       	 temp=code.substr(start,positions[j]-start+1);
       	 segments.push_back(temp);
         start=positions[j]+1;
       }
        temp=code.substr(start,code.length()-1-start);
	}
	return 0;
}