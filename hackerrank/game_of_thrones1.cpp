#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
  string s;
  cin>>s;
  long n=s.length();
  bool flag=false;
  int count=0;  
  unordered_map<char, long> h;
  
  for(long i=0;i<n;i++)
   h[s[i]]+=1;
 
  
for(int i=0;i<26;i++)
 {
   if(h[i+97]%2==1)
     count++;	
 }

 if(n%2==0 && count!=0)
 	cout<<"NO";
 else if(n%2==1 && count!=1)
 	cout<<"NO";
 else
     cout<<"YES";
}