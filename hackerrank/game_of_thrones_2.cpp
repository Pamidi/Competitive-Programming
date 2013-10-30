#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

bool ispal(string s)
{
   int i;
   for(i=0;i<(s.length()/2);i++)
      if(s[i]!=s[s.length()-1-i])
         break;
   if(i==s.length()/2)
   return true;

   return false;   
}

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
   	cout<<"0";
   else if((s.length()%2==1)&&odd_count!=1)
   	cout<<"0";
   else
   	{
         int count=0;
         vector<int> index;
         int j;
         for(j=0;j<s.length();j++)
             index.push_back(j);

         unordered_map<string,int> permut;

         do
         {
           
            string temp="";
            for(j=0;j<s.length();j++)
               temp+=s[index[j]];       //make a string of this combinaton
                  
            if(permut.find(temp)==permut.end())     
            {
            permut[temp]=1;
            if(ispal(temp))
                  count++;              
               
            }
         }while(next_permutation(index.begin(),index.end()));
        cout<<count<<endl;
      }

   return 0;

}