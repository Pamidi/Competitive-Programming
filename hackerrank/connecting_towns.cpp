#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
 {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	vector<int> route(n-1);
    	for(int i=0;i<n-1;i++)
    		cin>>route[i];
    	long long int result=1;
    	for(int i=0;i<n-1;i++)
    	{
    		result=(result*route[i])%1234567;
    	}
    	cout<<result<<endl;
    }
    return 0;
}
