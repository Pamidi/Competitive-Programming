 #include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <limits.h>

int main()
{
	ios::sync_with_stdio(false);
	long long int n,i,count=0;;
	cin>>n;
	long long int temp,prev=LLONG_MIN;
	for(i=0;i<n;i++)
	{
      cin>>temp;
      if(temp>prev&&temp>0)
      {
      	prev=temp;
      	 continue;
      	}
      else if(temp>prev&&temp<0)
      	{
      	 count++;
      	 prev=1;
      	}
      //tempK=prev
      else
      {
      	count++;
      	prev=prev+1;
      }

	}
	cout<<count<<endl;
	return 0;
}