#include <iostream>
using namespace std;
#include <string>
#include <cstdlib>
#include <algorithm>
#include <vector>

int main()
{
		int n,i;
		cin>>n;
		cin.ignore();
        for(i=0;i<n;i++)
        {
           string s;
           getline(cin,s);

           if(s.length()!=10)
           	  cout<<"NO"<<endl;
           	else
           	{
           		int valid=0;
           		for(int j=0;j<10;j++)
           		{
           			if(j==5||j==6||j==7||j==8)
           			 { if(!isdigit(s[j]))
                           {//cout<<j<<" NOT DIGIT"<<endl;
                           	valid=1;
                           	break;
                           }
                     }
                    else
                    {
                      if(!(isupper(s[j])))
                      	  {
                      	//  	cout<<j<<" CONDITION VIOLATED"<<endl;
                      	  	valid=1;
                      	  	break;
                      	  }
                    }      
           		}
           		if(valid==0)
           			cout<<"YES"<<endl;
           		else
           			cout<<"NO"<<endl;
           	}
        }
}