#include <iostream>
using namespace std;
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <sstream>

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int n;
		cin>>n;
		int count=0;
		for(long long int i=1;i*i<=n;i++)
		{
			if(n%i==0)
			{
				//i and n/i is a divisor...
				stringstream my_s;
				my_s<<i;
				string s1=my_s.str();
			    my_s.str("");
			    my_s<<n/i;
			    string s2=my_s.str();

                if(s1.find('4')!=string::npos||s1.find('7')!=string::npos)
                	count++;
                if(s2.find('4')!=string::npos||s2.find('7')!=string::npos)
                	count++;
			} 
		}
		cout<<count<<endl;
	}
	return 0;
}