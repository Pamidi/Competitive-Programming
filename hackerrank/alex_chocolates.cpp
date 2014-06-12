#include <iostream>
#include <unordered_map>
using namepsace std;

int main()
{
  int n;
  cin>>n;
  vector<string> a(n);
  string out="";
  unordered_map<char,int> h;

  for(int i=0;i<n;i++)
    cin>>a[i];
 
  out+=a[0];
  for(int j=0;j<out.length();j++)
  {  
    if(h[out[j]]!=1)
           h[out[j]]=1;
        else
           continue;
  }
   
  for(int i=1;i<n;i++)
  {
    out+=a[i];
    for(int k=0;k<out.length();k++)
       if(h[out[j]]==1)
         
  }

  

}