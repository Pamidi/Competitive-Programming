#include <iostream>
#include <cstdlib>
using namespace std;
#include <vector>
#include <map>
#include <string>

int main()
{
    int m,n,k;
   // cin>>m>>n>>k;
    m=5;
    n=3;
    k=2;
    cout<<m<<" "<<n<<" "<<k<<endl;
    int len=m,tot_len=m+n,start=0;
    cout<<len<<endl;
    cout<<tot_len<<endl;
    string out="";

    map<int,int> female;

    while(n--)
    {
       if(start==0)
       {
         start=start+k<len?start+k:start+k-n;
         len++;
         female[start]=1;
       }

       else
         {
          start=start+k+1<len?start+k+1:start+k+1-len;
          len++;
          female[start]=1;
         }
    }

    for(int i=0;i<tot_len;i++)                      //for loop to print the hash table
      cout<<i<<" "<<female[i]<<endl;
      cout<<endl;

    for(int i=0;i<tot_len;i++)
    {
      if(female[i]!=1)                             //making the output string
        out+="M";
      else
        out+="F";
    }
    for(int i=0;i<tot_len;i++)                     //printing the output string
        cout<<out[i];

    return 0;

}
