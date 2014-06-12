#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include <unordered_map>
#include <sstream>
#include <string>

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
   int t;
   cin>>t;
   cin.ignore();
   while(t--)
   {
   	string n;
   	getline(cin,n);
    
    if(n.length()<3)
    {
      int temp;
      stringstream obj1,obj2;
      obj1<<n;
      obj1>>temp;
      temp+=1000;
      obj2<<temp;
      n=obj2.str();
    }
   // cout<<"n:"<<n<<endl;
   	unordered_map<int,long long int> map;
   	for(int i=0;i<n.length();i++)
         map[n[i]-48]++;
  

     bool present_outer=false;
     for(int j1=0;j1<=992;j1+=8)
     {   bool present=true;
         stringstream obj;
         obj<<j1;
         string temp=obj.str();
         string temp1="";
         for(int h=0;h<3-temp.length();h++)
            temp1+='0';
         temp1=temp1+temp;
         if(j1<100)
         temp=temp1;
    //     cout<<"temp:"<<temp<<endl;
         for(int i=0;i<3;i++)
         {
            if(map[temp[i]-48]>0) 
                map[temp[i]-48]--;
            else
            {
        //       cout<<endl<<"failed at "<<i<<endl;
               for(int z=0;z<i;z++)
                  map[temp[z]-48]+=1;
               present=false;
               break;
            }    
         }
         if(!present)
           continue;
         present_outer=true;
         break;
     }
     if(!present_outer)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;  
  }
    return 0;
}
