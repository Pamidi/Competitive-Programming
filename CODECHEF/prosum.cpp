#include <iostream>
using namespace std;
#include <cstdlib>
#include <algorithm>
#include <vector>

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    long long int n;
    cin>>n;
    vector<long long int> a(n);
    for(long long int i=0;i<n;i++)
      cin>>a[i];
    long long int count_1=0,count_0=0,count_2=0;
    for(long long int i=0;i<n;i++)
    {
      if(a[i]==0) count_0++;
      if(a[i]==1) count_1++;
      if(a[i]==2) count_2++;
    }
    long long int ans,rem=n-(count_1+count_0);
    ans=(rem*(rem-1))/2;
    ans-=(count_2*(count_2-1))/2;
    cout<<ans<<endl;
  }
  return 0;
}