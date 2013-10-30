#include <iostream>
using namespace std;
#include <cstdlib>
#include <string>
#include <algorithm>

int main()
{
	int i,n;
	cin>>n;
	cin.ignore();
    for(i=0;i<n;i++)
    {
    	string s;
    	getline(cin,s);
    	int res=-1;
        int find1=s.find("hackerrank");
        int find2=s.rfind("hackerrank");
        if(find1==find2)
        {
        	if(s.length()==10)
        		res=0;
        	else if(find1==0) //at beginning
        		res=1;
        	else if(find1==s.length()-10) //at end
        		res=2;
        	else
        		res=-1;
        }
        else
        {
            if ((find1==0)&&(find2==s.length()-10)&&(find2-find1!=1))
            	res=0;
            else if (find1==0)
            	res=1;
            else if (find2==s.length()-10)
            	res=2;
            else
            	res=-1;
        }
     cout<<res<<endl;
    }
    return 0;
}