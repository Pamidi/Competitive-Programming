#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
#include <vector>
#include <stack>

int main()
{
	std::ios::sync_with_stdio(false);
	int t,i;
	string operators="+-*/^";
	cin>>t;
	cin.ignore();
    for(i=0;i<t;i++)
    {
    	string s;
    	int j;
    	getline(cin,s);
        
        if(s.length()==1)
        {
        	cout<<s;
        	continue;
        }
        stack<char> my_stack;
        for(j=0;j<s.length();j++)
        {   
        	if(s[j]=='(')
        		continue;
        	else if(s[j]==')')                                 //closing bracket
        	{
        	     cout<<my_stack.top();                    //pop operator
        	     my_stack.pop();
        	}
        	else if(operators.find(s[j])==string::npos)       //not operator
        		cout<<s[j];
        	else 
        		my_stack.push(s[j]);                 //push operator to stack
        	}
        cout<<endl;
    }
return 0;
}
