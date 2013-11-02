#include <iostream>
using namespace std;
#include <math.h>
#include <vector>

int main()
{
	ios::sync_with_stdio(false);
    vector<long long int> table(100001);
    table[0]=1;
    int i;
    int count=0;
	for(i=1;i<=100000;i++)
        {
             long long int num=(long long int) i*i;
        	 bool prob=false;
             while(num>0)
            {
            	int d=num%10;
            	if(d==2||d==3||d==5||d==6||d==7||d==8)
            	{   
            		prob=true;
            		break;
            	}
            	num=num/10;
            }
            if(!prob)
            count++;    
            table[i]=count;     
        }
        
	int t;
	cin>>t;
	while(t>0)
	{
		long long int a,b;
		cin>>a>>b;
		int first=ceil(sqrt(a));
		int last=ceil(sqrt(b));
		if(table[first]==table[last])
			cout<<"0"<<endl;
		else
		cout<<(table[last]-table[first]+1)<<endl;
		t--;
	}
	return 0;
}