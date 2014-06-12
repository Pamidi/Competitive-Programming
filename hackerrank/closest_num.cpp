#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

typedef long long int lli;

int main()
{
  long n;
  cin>>n;
  vector<int> a(n);
  for(long i=0;i<n;i++)
  	 cin>>a[i];
  sort(a.begin(),a.end());

  for(long i=0;i<n-1;i++)
  {
     cur_diff=a[i+1]-a[i];
     if(cur_diff<min_diff)
       {
       	 min_diff=cur_diff;
         start=i;
         end=j;
         cout<<a[i]<<" "<<a[i+1]<<" ";
       }




  }






}