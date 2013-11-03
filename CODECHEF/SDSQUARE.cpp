#include <iostream>
using namespace std;
#include <math.h>
#include <vector>

int main()
{
	ios::sync_with_stdio(false);
    vector<long long int> table(100001);
    vector<bool> is_perfect;
    is_perfect.resize(100001,false);
    table[0]=1;
    is_perfect[0]=true;
    int i;
    int count=1;
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
             {
                is_perfect[i]=true;   
                table[i]=count+1;
                count++;
            }
           else
            table[i]=count;     

        }
        
	int t;
    cin>>t;
	while(t>0)
	{int x=0,y=0;
    	long long int a,b;
		cin>>a>>b;
		int first=ceil(sqrt(a));
		int last=sqrt(b);
    //    cout<<"last:"<<last<<"  first:"<<first<<endl;
    //   cout<<"last value:"<<table[last]<<"  first value:"<<table[first]<<endl;
        if((last*last!=b)&&(first*first!=a))
        {
           cout<<table[last]-table[first]<<endl;
        }
        else if(last*last!=b)
        {
           
        }
        else if(first*first!=a)
        {

        }
        else
        cout<<(table[last]-table[first]+1)<<endl;
		t--;
	}
	return 0;
}