#include <iostream>
using namespace std;
#include <string>
#include <cstdlib>
#include <algorithm>
#include <vector>

bool validate_ip4(const string& s)
{
	if(s.length()>3)
		return false;
	for(int i=0;i<s.length();i++)
		if(!isdigit(s[i]))
			return false;
    int num=atoi(s.c_str());
    if(num>=0&&num<=255)
       return true;
  return false;   	
}

bool validate_ip6(const string& s)
{
	if(s.length()>4)
		return false;
    for(int i=0;i<s.length();i++)
    {
       int pos;
       pos=s.substr(i,1).find_first_of("abcdef0123456789");
       if(pos==string::npos)
       	  return false;
    }
    return true;
}

bool is_IPv4(const string& s)
{
	int i,count_dot=0;
	int pos=s.find(".",0);
	vector<int> dot_pos;
	while(pos!=string::npos)
	{
		count_dot++;
		dot_pos.push_back(pos);
		pos=s.find(".",pos+1);
	}
    if(count_dot!=3)
    	return false;

    int start=0;
    for(i=0;i<3;i++)                //the first 3 substrings..
    {
        string temp=s.substr(start,dot_pos[i]-start);
        if (!validate_ip4(temp))
        	return false;
        start=dot_pos[i]+1;
    }

    string last=s.substr(start);    //the last piece
    if (!validate_ip4(last))
       return false;

 return true;
}

bool is_IPv6(const string& s)
{
	int count_column=0;
	vector<int> column_pos;
    int pos=s.find(":",0);
    while(pos!=string::npos)
    {
    	count_column++;
    	column_pos.push_back(pos);
    	pos=s.find(":",pos+1);
    }	
    if(count_column!=7)
    	return false;

    int start=0;
    for(int i=0;i<7;i++)
    {
    	string temp=s.substr(start,column_pos[i]-start);
    	if (!validate_ip6(temp))
    		return false;
    	start=column_pos[i]+1;
    }
    string last=s.substr(start);
    if(!validate_ip6(last))
    	return false;
  return true;
}

int main()
{
	int n,i;
	cin>>n;
	cin.ignore();
    for(i=0;i<n;i++)
    {
      string s;
      getline(cin,s);
      if (is_IPv4(s))
      	cout<<"IPv4"<<endl;
      else if (is_IPv6(s))
      	cout<<"IPv6"<<endl;
      else
      	cout<<"Neither"<<endl;
    }
    return 0;
}