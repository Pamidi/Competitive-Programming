#include<iostream>

using namespace std;
long long int func(long long int n){
if(n == 0) return 1;
else
{
long long int t1;
if(n%2)
{
t1=func((n-1)/2);
return (2*(t1%1000000007)*(t1%1000000007))%1000000007;
}
else
{
t1=func(n/2);
return ((t1%1000000007)*(t1%1000000007))%1000000007;
}
}
}
int main(){
int t;
long long int n;
cin>>t;
while(t--){
cin>>n;

cout<<func(n)-1<<endl;
}
return 0;
}
