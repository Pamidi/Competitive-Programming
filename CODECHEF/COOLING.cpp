#include<iostream>
using namespace std;
#include<stdio.h>
#include <algorithm>
 
int main()
{
    int w[101],l[101];
    int t;
    cin>>t;
    if (t)
    while(t--!=0)
    {
        int j,i,n,ccount=0;
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>w[i];
        }
        for(i=0;i<n;i++)
        {
            cin>>l[i];
        }
 
sort(w,w+n);
sort(l,l+n);
 
        for(i=n-1,j=n-1;i>=0&&j>=0;)
        {
            if(w[i]<=l[j])
            {
                i--;
                j--;
                ccount++;
            }
            if (w[i]>l[j])
            {
                i--;
            }
 
        }
        cout<<ccount<<"\n";
    }
    return 0;
}
 