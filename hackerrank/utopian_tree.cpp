#include <iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
      int n;
      int h=1;
      cin>>n;
      int i=0;
      while(n--)
      {
        if(i==0)
        {
          h=h*2;
          i=1;
        }
        else
        {
          h=h+1;
          i=0;
        }
        }
        cout<<h<<endl;
      }
}

