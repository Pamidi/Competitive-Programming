#include <iostream>
using namespace std;
#include <cstdlib>
#include <vector>
#include <algorithm>

class Zigzag
{
 public:
   int longestZigZag(vector<int>);
};

int Zigzag::longestZigZag(vector<int> seq)
{
   vector<vector<int> > out_table(seq.size());
   for(int i=0;i<seq.size();i++)
   	  out_table[i].resize(2);
   
   for(int i=0;i<seq.size();i++)					//initialize
   {
   	   out_table[i][0]=0;							//previous-element smaller
   	   out_table[i][1]=0; 							//previuos-element larger
   }
   out_table[0][0]=1;                               //change only one set in first set.

   for(int i=1;i<seq.size();i++)					//starting from second element.
   {
   	   if(seq[i]>seq[i-1])							//previous-element smaller
   	   {
         out_table[i][0]=out_table[i-1][1]+1;
         out_table[i][1]=out_table[i-1][0];
   	   }
   	   else
   	   {
         out_table[i][1]=out_table[i-1][0]+1;
         out_table[i][0]=out_table[i-1][1];
   	   }
   }
  return max(out_table[seq.size()-1][1],out_table[seq.size()-1][0]);
}

int main()
{
   int a[]={16,2,10,5,2,5};
   vector<int> seq(a,a+sizeof(a)/sizeof(a[0]));
   Zigzag obj;
   cout<<obj.longestZigZag<<endl;
   return 0;
}