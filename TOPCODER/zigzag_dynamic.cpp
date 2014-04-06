#include <iostream>
using namespace std;
#include <cstdlib>
#include <algorithm>
#include <vector>

class ZigZag
{
public:
      int longestZigZag(vector<int> sequence)
      {
          vector<int> difference(sequence.size()-1);
          int k=sequence.size()-1;
          if(k==0)
          	return 1;
          for(int i=0;i<k;i++)
          	 difference[i]=sequence[i+1]-sequence[i];
          
          int i;
          for(i=0;difference[i]==0;i++)
          {}

          if(i==k)
          	 return 0;

          int last_sign=0;
          if(sequence[1]-sequence[0]>0)
            last_sign=1;
          int len=2;         //first pair chosen 
          bool consec=false;
          int last_value=sequence[1];
          i++;
          for(;i<k;i++)
          {
              int cur_sign=0;
               //ith pair now
               if(difference[i]>0)
                  cur_sign=1;
               if(consec&&cur_sign!=last_sign)
               {
                  int temp_sign=0;
                  if(sequence[i]-last_value>0)
                       temp_sign=1;  
                  if(temp_sign!=last_sign)
                  {
                     len++;
                     last_sign=temp_sign;
                     last_value=sequence[i];
                  }
                  else
                  {
                  temp_sign=0;
                  if(sequence[i+1]-last_value>0)
                     temp_sign=1;
                  if(temp_sign!=last_sign)
                  {
                     len++;
                     last_sign=temp_sign;
                     last_value=sequence[i];
                  }
                  }
               consec=false;
               }
              if(cur_sign!=last_sign)
              {
                 len++;
                 last_value=sequence[i+1];
                 last_sign=cur_sign;
              } 
              if(cur_sign==last_sign)
              {
                consec=true;
              }
              cout<<"considering pair "<<sequence[i]<<" and "<<sequence[i+1]<<endl;
              cout<<"last value:"<<last_value<<endl;
              cout<<"last sign:"<<last_sign<<endl;
              cout<<"consec:"<<consec<<endl;
              cout<<endl;
          }
          return len;
        }
};

int main()
{
   int ar[]={ 70, 55, 13, 2, 99, 2, 80, 80, 80, 80, 100, 19, 7, 5, 5, 5, 1000, 32, 32 } ;
   vector<int> sequence(ar,ar+sizeof(ar)/sizeof(ar[0]));
   ZigZag obj;
   cout<<obj.longestZigZag(sequence)<<endl;
   return 0;
}