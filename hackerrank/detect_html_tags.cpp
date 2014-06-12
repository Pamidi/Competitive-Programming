#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

int main()
{
	int n;
	cin>>n;
	cin.ignore();
    unordered_map<string,int> hash_tag;
    vector<string> tags;
    while(n--)
    {
        string temp;
        getline(cin,temp);
        long k=temp.length();
        for(long i=0;i<k;)
        {
            if(temp[i]=='<')
            {
                 i++;
                 string cur="";
                 while(isspace(temp[i]))
                   i++;
                 if(temp[i]=='/')
                 {
                    i++;
                    continue;
                 }
                 while(temp[i]!=' '&&temp[i]!='>'&&temp[i]!='/')
                    cur+=temp[i++];
                 if(hash_tag[cur]!=1)
                 {
                    hash_tag[cur]=1;
                    tags.push_back(cur);
                 } 
            }
            i++;
        }
    sort(tags.begin(),tags.end());
    int i;
    for(i=0;i<tags.size()-1;i++)
        cout<<tags[i]<<";";
    cout<<tags[i];

}   