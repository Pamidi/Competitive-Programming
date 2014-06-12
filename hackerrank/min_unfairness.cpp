  #include <iostream>
  #include <algorithm>
  #include <vector>
  #include <limits.h>
  using namespace std;

  int main()
  { 
    long n,k;
    cin>>n;
    cin>>k;
    vector<long long int> a(n);
    for(long i=0;i<n;i++)
      cin>>a[i];
    sort(a.begin(),a.end());
    
    long long int unfair=LLONG_MAX;
    for(long i=0;i<=n-k;i++)
      unfair=min(unfair,a[i+k-1]-a[i]);

    cout<<unfair;
  }