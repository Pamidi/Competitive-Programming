#include <iostream>
using namespace std;
#include <cstdlib>
#include <string>

int main()
{
	string input="ravi teja p";
	bool space_follow=true;
	for(int i=0;i<input.length();i++)
	{
       if(space_follow)
       	  input[i]=toupper(input[i]);
	   if(isspace(input[i]))
	   	   space_follow=true;
	   else
	   	   space_follow=false;
	}
	cout<<input<<endl;
	return 0;
}