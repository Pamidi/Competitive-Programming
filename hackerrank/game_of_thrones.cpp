#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

int main()
{
   string s;
   string alphabets="abcdefghijklmnopqrstuvwxyz";
   getline(cin,s);

   unordered_map<char,int> hash_map(s.length()); 
   int i;
   for(i=0;i<26;i++)
     hash_map[alphabets[i]]=0;	 
   
   for(i=0;i<s.length();i++)
   {
   	  hash_map[s[i]]++;
   }

   int odd_count=0;

   for(i=0;i<26;i++)
   {
   	if(hash_map[alphabets[i]]%2==1)
   		odd_count++;
   }
   if((s.length()%2==0)&&odd_count!=0)
   	cout<<"NO";
   else if((s.length()%2==1)&&odd_count!=1)
   	cout<<"NO";
   else
   	cout<<"YES";

   return 0;

}