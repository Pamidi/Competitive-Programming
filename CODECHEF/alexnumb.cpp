#include <iostream>
using namespace std;
#include <cstdlib>
#include <vector>
#include <algorithm>

int main()
{
int t;
cin>>t;
while(t--)
  {
    long long int n;
    cin>>n;
    vector<long long int> a(n);
    for(int j=0;j<n;j++)
    cin>>a[j];
    cout<<(n*(n-1))/2<<endl;
  }
return 0;
}
