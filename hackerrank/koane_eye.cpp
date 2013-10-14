#include<iostream>
using namespace std;
#include <cstdlib>
#include <stack>
#include <cstring>
#include <algorithm>

int main()
{
   stack<string> input;
	for(int i=0;i<6;i++)
	   { 
	      string num;
	      getline(cin,num);
	      reverse(num.begin(),num.end());
	      input.push(num);
	   }
	for(int i=0;i<6;i++)
	{
		cout<<input.top()<<endl;
		input.pop();
	}
	return 0;
}
