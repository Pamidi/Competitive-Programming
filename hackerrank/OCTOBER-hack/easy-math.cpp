#include <iostream>
using namespace std;
#include <algorithm>
#include <string>
#include <vector>
#include <cstdlib>

long long int check_div(long long int x,vector<string> &table)
{
      if(table.size()==0)       //special case
      {
          table.push_back("4");
          if(4%x==0)            //4 divides x
           return 2;            //value 
      }      
      else
      {
      	  long long int i,num1,num2,a,b;
      	  int k=table.size();
      	  for(i=0;i<k;i++)
      	  {
      	  	 string temp1=table[i];
             string temp2=temp1;          //make two copies
             temp1.insert(0,"4");         //4 at beginnig
             temp2+="0";                  //0 at end
             num1=atoll(temp1.c_str());
             num2=atoll(temp2.c_str());
             if(num1%x==0)
             {
               a=count(temp1.begin(),temp1.end(),'4');
               b=count(temp1.begin(),temp1.end(),'0');
               return 2*a+b;
             }
             if(num2%x==0)
             {
               a=count(temp2.begin(),temp2.end(),'4');
               b=count(temp2.begin(),temp2.end(),'0');
               return 2*a+b;
             
             }
             table.push_back(temp1);
             table.push_back(temp2);
      	  }
      }
   long long int temp=check_div(x,table);
   if(temp>0)
   	return temp;
}

int main()
{
	int t,i;
	cin>>t;
	for(i=0;i<t;i++)
	{
		long long int x;
		cin>>x;
		vector<string> table;
		cout<<check_div(x,table)<<endl;
    }
	return 0;
}