#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main()
 {
    int n,t;
    cin>>n>>t;
    vector<int> w(n);
    for(int i=0;i<n;i++)
        cin>>w[i];
    
    while(t--)
    {
        int i,j;
        cin>>i>>j;
        int min=INT_MAX;
        for(int k=i;k<=j;k++)
          {  
            if(w[k]<min)
              min=w[k];
          }  
        cout<<min<<endl;
    }
    
}
   
    