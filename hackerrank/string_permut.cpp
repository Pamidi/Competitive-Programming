#include <iostream>
using namespace std;
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

unordered_map<int,int> map;
string a="0123456789";
	
void find_attributes(char a,int &sub_var,int &add_var)
{
		if(isdigit(a)) {sub_var=48;add_var=0;}
		if(islower(a)){sub_var=97;add_var=10;}
		if(isupper(a)){sub_var=65;add_var=36;}
}

void generate_permutation(int track,string current)
{
	if(track==a.length())
	{
		cout<<current<<endl;
		return;
	}
	//pick one value for slot
	for(int i=0;i<a.size();i++)
	{
		int sub_var,add_var;
		find_attributes(a[i],sub_var,add_var);
		if(map[a[i]-sub_var+add_var]>0)
		{
			//pick it;
			map[a[i]-sub_var+add_var]--;
			generate_permutation(track+1,current+a[i]);
			map[a[i]-sub_var+add_var]++;
		}
	}
      
}

int main()
{
	for(int i=0;i<a.length();i++)
	{
		//can contain digits or alphabet(uppercase or lowercase)
		int sub_var,add_var;
		find_attributes(a[i],sub_var,add_var);
	    map[a[i]-sub_var+add_var]++;
	}

	//start generating permutation
	generate_permutation(0,"");
    return 0;
}