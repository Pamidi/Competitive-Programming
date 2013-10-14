#include<iostream>
using namespace std;
#include<cstring>

int main()
{
    int a[100],i,j;
    for(i=0;i<100;i++)a[i]=0;
    int n,input,result;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>input;
        a[input]++;
        if(a[input]<=1)
            result=input;
    }
    cout<<result<<endl;
    return 0;
    
}