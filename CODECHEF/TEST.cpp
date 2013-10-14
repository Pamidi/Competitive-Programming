#include<iostream>
using namespace std;
int main()
{ int a[1000],n=0,i=0;
 while(n!=42)
{ cin>>a[i];
n=a[i++];}
for(int j=0;j<(i-1);j++)
{cout<<a[j]<<endl;}
return 0;}
 
