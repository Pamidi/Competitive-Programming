#include <iostream>
using namespace std;
#include <vector>
#include <cstdlib>
#include <string>
#include <algorithm>

int main()
{
	int t,i;
	cin>>t;
	for(i=0;i<t;i++)
	{
		int k;
		string p,q;
		cin>>k>>p>>q;

		int l,i,j,z,answer=0;
		int n=p.length();
		for(l=n;l>=1;l--)
		{
			for(i=0;i<n-l+1;i++)
			{  //p[i]...p[i+l-1]
				for(j=0;j<n-l+1;j++)
				{ //q[j]...q[j+l-1]
                   int count=0;
                   for(z=0;z<l;z++)
                       if(p[i+z]!=q[j+z])
                       	count++;
                   if(count<=k)
                   	{answer=l;
                   		break;
                   	}
                }
				if(answer!=0)
					break;
			}
			if(answer!=0)
				break;
		}
		cout<<answer<<endl;

	}
	return 0;
}