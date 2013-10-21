#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <cstdlib>

class MagicWords
{
public:
		int count(vector <string> S,int K);
};

void calc_magic_word(string s,int &count,int k)
{
  for(int i=0;i<s.length();i++)
  { int j;
  	for(j=0;j<s.length();j++)
  	{
        if(s[j]==s[(j+i)%s.length()])
        	continue;
        else
        	break;
        if(j==s.length())
        	k--;
  	}
  }
  if(k==0)
  count++;
}

int MagicWords::count(vector <string> S,int K)
{
   vector<int> p(S.size());
   for(int i=0;i<S.size();i++)
   p[i]=i;
   int count=0;
   do
   { 
   	string cur="";
      for(int i=0;i<p.size();i++)
          cur+=S[i];
      calc_magic_word(cur,count,K);
   }while(next_permutation(p.begin(),p.end()));    
return count;
}

int main()
{
   
}