#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool no_of_primes(int n)
{
  int k=n;
  cout<<k;
  int count=0;
  vector<int> p(k+1);

  for(int i=0;i<=k;i++)
  	p[i]=0;

  for(int i=2;i<=sqrt(k);i++)
   {
   	for(int j=2*i;j<=k;j+=i)
     p[j]=1;
   }

  for(int i=2;i<=k;i++)
    {
      if(p[i]==0)
       count++;
    }
  return count;
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;

    vector<int> c(n);
    c[0]=1;
    c[1]=1;
    for(int i=2;i<=n;i++)
      {
      	if(i>=4)
      	c[i]=c[i-1]+c[i-4];
      else
      	c[i]=c[i-1];
      }
   //cout<<c[n];
   cout<<no_of_primes(c[n]);
  }
 }