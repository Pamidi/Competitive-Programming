#include <iostream>
#include <unordered_map>
using namespace std;

typedef long long int lli;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
  	lli n;
  	cin>>n;
    int digit;
    lli answer=0;
    lli num=n;
    unordered_map<int,int> h; 
    while(num>0)
    {
      digit=num%10;
      //cout<<"digit:"<<digit<<endl;
      h[digit]=1;
      num=num/10;
     // cout<<"num:"<<num<<endl;
    }
    
    for(int i=1;i<=9;i++)
      {
        //cout<<"h"<<"["<<i<<"]"<<"  "<<h[i]<<endl; 
       	if(h[i]!=0 && n%i==0)
      	 answer++;
      	//cout<<"ans:"<<answer<<endl;
      }
    cout<<answer<<endl;
  }
}