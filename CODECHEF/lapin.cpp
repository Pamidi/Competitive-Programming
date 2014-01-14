#include <iostream>
using namespace std;
#include <string>
#include <cstdlib>
#include <algorithm>

int main()
{
int t;
cin>>t;
cin.ignore();
while(t--)
{
  string s;
  getline(cin,s);
  int first[26]={0},second[26]={0};
  bool is_odd=false;
  if(s.length()%2==1) is_odd=true;
  int n=s.length();
  for(int i=0;i<s.length();i++)
  {
    if(is_odd&&(i==(n/2)))
        continue;
    if(i<(n/2))
         first[s[i]-97]++;
    else
         second[s[i]-97]++;
  }
 bool found=false;
 for(int i=0;i<26;i++)
  {
     if(first[i]!=second[i])
     {
       found=true;
       cout<<"NO"<<endl;
       break;
     }
  }
 if(!found)
      cout<<"YES"<<endl;
}
return 0;
}
