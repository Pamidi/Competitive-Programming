#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	const long long int module=100000;
    	long long int ans=1;
    	for(int i=0;i<n;i++)
    		ans=(ans*2)%module;
    	cout<<ans-1<<endl;
    }
    return 0;
}
