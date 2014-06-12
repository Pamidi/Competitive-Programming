#include <iostream>
#include <string>
using namespace std;

int main()
{
  int n;
  cin>>n;
  string a[n];
  for(int i=0;i<n;i++)
   cin>>a[i];

  int m[n][26];
  for(int i=0;i<n;i++)
   {
     string out=a[i];
     for(int j=0;j<out.length();j++)
       m[i][out[j]-97]=1;
   }
  
  bool flag=true;
  int count=0;

  for(int i=0;i<26;i++)
   {
     for(int j=0;j<n;j++)
        if(m[j][i]!=1)
         {
           flag=false;
           break;
         }
     if(flag)
        count++;
   }

  cout<<count<<endl;
}
