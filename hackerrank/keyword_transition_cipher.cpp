#include <iostream>
using namespace std;
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

int main()
{
	int n;
	cin>>n;
	cin.ignore();
	while(n--)
	{
		string keyword,cipher,mod_keyword="";
		getline(cin,keyword);
		getline(cin,cipher);

        unordered_map<int,int> char_map;
        unordered_map<int,bool> char_seen;
        for(int i=0;i<26;i++)                           //for A..Za..z
        {
        	char_seen[i]=false;
        	char_map[i]=0;
        }
        for(int i=0;i<keyword.length();i++)
        	char_map[keyword[i]-65]++;
        for(int i=0;i<keyword.length();i++)
        {
            if(!char_seen[keyword[i]-65])
            {
            	char_seen[keyword[i]-65]=true;
            	mod_keyword+=keyword[i];
            }
        }
        keyword=mod_keyword;

        unordered_map<int,int> start_index;
        for(int i=0;i<keyword.length();i++)
        	start_index[keyword[i]-65]=i;

        vector<string> string_table;
        string_table.push_back(keyword);
		 
        int p=keyword.length();
        
 
        int count=0;
        string temp="";
        for(int i=0;i<26;i++)
        {
            //check if character is there in keyword
            if(char_map[i]==0)
            {
            	temp+=char(65+i);
            	count++;
            	if(count==p)
            	{
            		string_table.push_back(temp);
            		temp="";
            		count=0;
            	}
            }
        }
        if(count>0&&count<p)
        	string_table.push_back(temp);

        string substitution="";
        sort(keyword.begin(),keyword.end()); 
        unordered_map<int,int> decipher;


        int count1=0;
        for(int i=0;i<keyword.length();i++)
        {
        	int k,j=start_index[keyword[i]-65];
        	for(k=0;k<26/p;k++)
        	{
        		decipher[string_table[k][j]-65]=count1;
        		count1++;
        		substitution+=string_table[k][j];
        	}
        	if(j<(26%p))
        	{
        		decipher[string_table[k][j]-65]=count1;
        		count1++;
        		substitution+=string_table[k][j];
        	}
        }
        for(int i=0;i<cipher.length();i++)
        {
        	if(isspace(cipher[i]))
        		cout<<" ";
        	else
        	{
        		cout<<char(65+decipher[cipher[i]-65]);
        	}
        }
        cout<<endl;
	}
}