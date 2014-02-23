#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <string>
#include <unordered_map>

void print_combination(string &s,vector<string> &combinations,int index)
{
    if(index==s.length())
    	return;

    //add s[index] to all strings in combinations;
    int k=combinations.size();
    for(int i=0;i<k;i++)
    {
    	string temp=combinations[i]+s[index];
    	combinations.push_back(temp);
    }
    string temp="";
    temp=s[index];
    combinations.push_back(temp);             //adding that character alone
    print_combination(s,combinations,index+1);
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cin.ignore();
		string s;
		vector<string> combinations;
		getline(cin,s);
		print_combination(s,combinations,0);
	    sort(combinations.begin(),combinations.end());
	    auto it=unique(combinations.begin(),combinations.end());
	    combinations.resize(distance(combinations.begin(),it));
	    for(int j=0;j<combinations.size();j++)
	    	cout<<combinations[j]<<endl;
   }
}