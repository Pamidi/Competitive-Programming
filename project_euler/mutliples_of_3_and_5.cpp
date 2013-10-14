#include<iostream>
using namespace std;
#include<cstdlib>

int main()
{
    int sum=0;
    for(int i=3;i<999;i++)
    {
        if(i%15==0)
            sum+=i;
        else if(i%3==0)
            sum+=i;
        else if(i%5==0)
            sum+=i;
    }
    cout<<count;
    return 0;
}
