#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int getbest(int i,int j,int k,string h,string m)
{
  int i1=i,j1=j,l=0;
  int best=0,bad=0;
  string p=h;
  string q=m;
  int n=p.length();
  while(true)
  {
    if(i1+l>n || j1+l>n)
      return max(best,l);
    
    if(p[i1+l]!=q[j1+l])
    	bad+=1;

    if(bad>k)
     { 
       best=max(best,l);
       while(p[i1]==q[j1])
       {
         i1=i1+1;
         j1=j1+1;
         l=l-1;
       }
       bad=bad-1;
       i1=i1+1;
       j1=j1+1;
     }
    else
    	l=l+1;
  }

  return best;
}


int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int k;
    cin>>k;
    string p,q;
    cin>>p>>q;
    int n=p.length();
    int best=0;
    for(int i=0;i<n;i++)
    best=max(best,max(getbest(0,i,k,p,q),getbest(i,0,k,p,q)));
    cout<<best<<endl;
  }
}