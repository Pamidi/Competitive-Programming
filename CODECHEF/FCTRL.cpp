#include<iostream>
using namespace std;
#include<string.h>
#include<cstdlib>
#include<cmath>
 
int main()
{
    int size,k,z,num,i=0;
    cin>>size;
    int res[size],j=1;
    for(z=0;z<size;z++)
     res[z]=0;
 
    while(size>0)
    { j=1;
        cin>>num;
 
        while(num>=(pow(5,float(j))))
          {
              res[i]+=num/(pow(5,float(j)));
                        j++;
 
          }
 
      i++;
      size--;
    }
 
     for(i=0;i<z;i++)
     cout<<res[i]<<endl;
 //return 0;
}
 
