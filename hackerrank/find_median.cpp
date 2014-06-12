#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

typedef long long int lli;

lli partition(vector<int> &ar,lli p,lli q)
{
   lli left=p,right=q;
   int pivot=ar[p];
   while(left<right)
   {
      while(ar[left]<=pivot)
         left++;
      while(ar[right]>pivot)
         right--;
      if(left<right)
      {
         int temp=ar[left];
         ar[left]=ar[right];
         ar[right]=temp;
      }
   }
   ar[p]=ar[right];
   ar[right]=pivot;
   return right;
}

int find_kth_largest(vector<int> &ar,lli p,lli q,lli k)
{
  //cout<<"p:"<<p<<"   "<<"q:"<<q<<"   "<<"k:"<<k<<endl;
  lli pos=partition(ar,p,q);
  //cout<<"pos:"<<pos<<endl;
  lli temp=pos-p+1;
  //cout<<"temp:"<<temp<<endl;
  if(temp==k)
  { 
    //   cout<<"equal case!"<<endl<<endl; 
       return ar[pos];
  }
  if(temp>k)
  {
    //   cout<<"left side"<<endl<<endl;
       return find_kth_largest(ar,p,pos-1,k);
  }
  else
  {
    //   cout<<"right side"<<endl<<endl;
       return find_kth_largest(ar,pos+1,q,k-temp);
  }
}

int find_median(vector<int> &ar,lli n)
{
    if(n==1)
       return ar[1];
    return find_kth_largest(ar,1,n,(n/2)+1);
}

int main()
{
    lli n;
    cin>>n;
    vector<int> ar(n+1);
    for(lli i=1;i<=n;i++)
        cin>>ar[i];
    int k=find_median(ar,n);    
    cout<<k<<endl;
    
}