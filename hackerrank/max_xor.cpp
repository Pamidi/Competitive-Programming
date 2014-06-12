#include <iostream>
#include <math.h>
using namespace std;

int convert_to_binary(int r)
{
  int num=r;
  int count=0;
  int rem=0;
  while(num>0)
  {
    num=num/2;
    rem=num%2;
    count++;
  }
 return count;
}

int convert_to_decimal(int count)
{
  int num=0;
  int p=1;
  int k=count;
  int i=0;
  while(k--)
  {  
   num+=p*pow(2,i);
   i++;
  }
  return num;
}

int main()
{
  int l,r;
  cin>>l>>r;
  int k=convert_to_binary(r);
  int max_val=convert_to_decimal(k);
  cout<<max_val;
}

