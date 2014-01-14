#include <iostream>
using namespace std;
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
int t;
cin>>t;
cin.ignore();
for(int i=0;i<t;i++)
{
   string s;
   getline(cin,s);
   int count[52];
   for(int j=0;j<52;j++)
      count[j]=0;
   for(int j=0;j<s.length();j++)
     {
         if(s[j]<=90)
           count[s[j]-65]++;
         else
           count[s[j]-71]++;
     }
   int ans=0;
   for(int j=0;j<52;j++)
     ans+=((count[j]+1)/2);
   cout<<ans<<endl;
}
return 0;
}
