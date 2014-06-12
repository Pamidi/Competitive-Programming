#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
     int n,a,b;
     cin>>n>>a>>b;
     int k=n;
     int num=0;
     vector<int> ar(n);
     unordered_map<int,int> h;

     for(int i=1;i<=n;i++)
     {	num=0;
     	num=num+(n-i)*a+(i-1)*b;
        ar[i-1]=num;
     }

     sort(ar.begin(),ar.end());
     
     for(int i=0;i<n;i++)
     	{
     	  if(h[ar[i]]!=1)
     		h[ar[i]]=1;
     	  else
     	  	continue;
     	}
       
     for(int i=0;i<n;i++)
     	{ 
          if(h[ar[i]]==1)
     	  cout<<ar[i]<<" ";
          h[ar[i]]=0;
        }
     cout<<endl;
    }
}