#include <iostream>
using namespace std;
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

int main()
{
	int t;
	string transform;
	cin>>t;
	cin.ignore();
	getline(cin,transform);
    unordered_map<char,char> map_char;

	for(int i=0;i<transform.length();i++)
		map_char[97+i]=transform[i];
	while(t--)
	{
		string sentence,output="";
		getline(cin,sentence);
		for(int i=0;i<sentence.length();i++)
		{
		    char ch=sentence[i];
		    if(ch=='_')
		    {  
		       output+=' ';
		    }
		    else if(ch=='.'||ch==','||ch=='!'||ch=='?')
		    {  
		    	output+=ch;
		    	continue;
		    }
            else
            {
            	if(isupper(ch))
				   {
				   	output+=toupper(map_char[tolower(ch)]);
				   }
				else
				  {
				   output+=map_char[ch];
				  }
            }    	    
        }
		cout<<output<<endl;
	}
return 0;
}