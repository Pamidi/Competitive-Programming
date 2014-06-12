#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int n;
	cin>>n;
	while(n--)
    {
       int num=0;
       if(n%2==0)
         {
          num=-1;
          cout<<num<<endl;
         }
       if(n%3==0)
       	 {
           int i=n-1;
           while(i--)
           	num+=5*(10**i);
            cout<<num<<endl;
         }
       if(n%5==0)
          {
           int i=n-1;
           while(i--)
           	num+=3*(10**i);
            cout<<num<<endl;
         }

       if(n%3!=0&&n%5!=0)
         {
           




         }


    }



}