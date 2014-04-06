#include <iostream>
using namespace std;
#include <cstdlib>
#include <algorithm>
#include <vector>

class AccessChanger
{
public:
	vector<string> convert(vector<string> input)
    {
       vector<string> output(input.size());
       for(int i=0;i<input.size();i++)
       {
       	  if(input[i].length()==1)
       	  {
       	  	  output[i].push_back(input[i][0]);
              continue;
          }
          int comment=input[i].length();
          int j;
          for(j=0;j<input[i].length()-1;j++)
          {
          	  if(input[i][j]=='-'&&input[i][j+1]=='>')
          	  {
          	  	 output[i].push_back('.');
          	  	 j+=1;
          	  }
          	  else if(input[i][j+1]=='/'&&input[i][j]=='/')
          	  {
          	  	 comment=j;
          	  	 break;
          	  }
          	  else
          	  	output[i].push_back(input[i][j]);
          }
          if(comment==input[i].length())
          {
          	  //check for last character
          	  if(input[i][j-1]=='-'&&input[i][j]!='>')
          	  	output[i].push_back(input[i][j]);
          }
          for(int j=comment;j<input[i].length();j++)
          	   output[i].push_back(input[i][j]);
       }
      return output;
	}
};

int main()
{
	const char* p[]={"Test* t = new Test();", "t->a = 1;", "t->b = 2;", "t->go(); // a=1, b=2 --> a=2, b=3"};
    vector<string> input(p,p+sizeof(p)/sizeof(p[0]));
    AccessChanger obj;
    vector<string> out=obj.convert(input);
    for(int i=0;i<out.size();i++)
    	cout<<out[i]<<endl;
    return 0;
}