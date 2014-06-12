#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main()
{
  int n;
  cin>>n;
  vector<int> a(n);
  unordered_map<int,int> h;

  for(int i=0;i<n;i++)
    cin>>a[i];
  
  for(int i=0;i<n;i++)
  	h[a[i]]+=1;

  for(int i=0;i<n;i++)
   {  
   	  if(h[a[i]]!=2)
  		cout<<a[i];
   }
}
