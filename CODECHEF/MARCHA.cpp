#include <iostream>
#include<cstdio>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int ar[n];
        for(int i=0;i<n;i++){
            cin>>ar[i];
        }
        int bound=1<<n;
        int flag=0;
        for(int i=0;i<bound;i++){
            int temp=i;
            int sum = 0;
            int j=0;
            int value = 1;
            while(value<=temp){
                if((temp&value)>0){
                    sum =sum+ar[j];
                }
                j++;
                value=value<<1;
            }
            if(sum==m){
               flag=1;
            }
        }
        if(flag){
            cout<<"Yes"<<endl;
        }
        else
            cout<<"No"<<endl;
    }
    return 0;
}