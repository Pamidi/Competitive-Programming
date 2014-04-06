#include <iostream>
using namespace std;
#include <algorithm>
#include <string>
#include <vector>

int main()
{
  const char* s[]={"creation","sentence","reaction","sneak","star","rats","snake"};
  vector<string> v(s,s+sizeof(s)/sizeof(s[0]));
  for(int i=0;i<v.size();i++)
    sort(v[i].begin(),v[i].end());
  sort(v.begin(),v.end());
  string temp=v[0];
  int i=1,ans=1;
  
  for(int i=1;i<v.size();i++)
  {
  	if(temp==v[i]) continue;
  	temp=v[i];
  	ans++;
  }

  cout<<ans<<endl;
  return 0;
}