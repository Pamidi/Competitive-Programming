#include <iostream>
using namespace std;
#include <string>
#include <cstdlib>
#include <vector>

int main()
{
	int n,i;
	cin>>n;
	vector<string> input(n);
	cin.ignore();
	for(i=0;i<n;i++)
	{
		getline(cin,input[i]);
	}
	int t;
	cin>>t;
	for(i=0;i<t;i++)
	{
		string word;
		cin>>word;
		int count=0;
		  for(int j=0;j<n;j++)
		  {
		  	 int pos=input[j].find(word,0);
		  	 while(pos!=string::npos)
		  	 {
		  	 	int prob=0;
		  	 	if(pos==0)
		  	 	{
                     if(isalnum(input[j][pos+1])||input[j][pos+1]=='_')
                     	 prob=1;
		  	 	}
		  	 	else if (pos==input[j].length()-1)
		  	 	{
                    if(isalnum(input[j][pos-1])||input[j][pos-1]=='_')
                    	prob=1;
		  	 	}
		  	 	else
		  	 	{
                    if((isalnum(input[j][pos+1]||input[j][pos+1]=='_'))||(isalnum(input[j][pos-1])||input[j][pos-1]=='_'))
                    	prob=1;
		  	 	}
		  	 	if(prob==0)
		  	 	count++;
		  	 	pos=input[j].find(word,pos+1);
		  	 }
		  }
		  cout<<count<<endl;
	}
	return 0;
}