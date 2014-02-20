#include <iostream>
using namespace std;
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <sstream>
#include <limits.h>
#include <cmath>

typedef long long int LLI;

int main()
{
	int divident=pow(10,9)+7;
	int t;
	cin>>t;
	while(t--)
	{
      LLI m,n,i,h_seg=1,v_seg=1,min_cost=0,temp1,temp2;
      cin>>m>>n;
      vector<int> y(m-1),x(n-1);
      for(i=0;i<m-1;i++)
      		cin>>y[i];
      for(i=0;i<n-1;i++)
      	    cin>>x[i];
      
      make_heap(y.begin(),y.end(),less<int>());
      make_heap(x.begin(),x.end(),less<int>());   //make max-heaps out of x and y
      
      i=m+n-2;
      while(i>0)
      {
           //pick the most appropriate cut
      	   temp1=y.size()>0?y.front():LLONG_MIN;
           temp2=x.size()>0?x.front():LLONG_MIN;
           if(temp1>=temp2)                   //going to choose a horizontal cut
           {
           	//  cout<<" y cut with cost:"<<temp1<<endl;
              v_seg++;
              min_cost+=temp1*h_seg;
              pop_heap(y.begin(),y.end(),less<int>());
              y.pop_back();
           }
           else								  //going to choose a vertical cut
           {
            //  cout<<" x cut with cost:"<<temp2<<endl;
              h_seg++;
              min_cost+=temp2*v_seg;
              pop_heap(x.begin(),x.end(),less<int>());
              x.pop_back();
           }
           i--; 
      }
      cout<<min_cost%divident<<endl;      
	}
 return 0;
}