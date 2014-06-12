#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
#include <vector>

void get_best_length_slide_from(string &a,string &b,int i,int j,int k,int &best)
{
	//p and q be the sliding pointers on both the strings
	int end=a.length();
	int p=i,q=j,l=0;
    int bad=0;
	while(true)
	{
	   if(p+l==end||q+l==end)
      {
         best=max(best,l-1);
         break;
      }
      if(a[p+l]!=b[q+1])
      {
      	bad++;
        if(bad>k)
        {
      	  best=max(best,l-1);
      	  while(a[p]==b[q])
      	  {
      	 	p++;
      	 	q++;
      	  }
      	  bad--;
      	  p++;
      	  q++;
        }
        else
        	l=l+1;
      }
      else
      	    l=l+1;
   }
}

int main()
{
	int t;
	cin>>t;
	while(t--)
    {
    	int k;
    	string p,q; 
    	cin>>k>>p>>q;

    	int len1=p.length();
    	
    	int best=0;
    	for(int i=0;i<len1;i++)
    		best=max(best,max(get_best_length_slide_from(p,q,i,0,k,best),get_best_length_slide_from(p,q,0,i,k,best));

        cout<<best<<endl;
    }
}