#include <iostream>
using namespace std;
#include <vector>
#include <cstdlib>
#include <algorithm>

long find_words(int m,int n,int constraint,vector<vector<long> > &table)
{
	//m is size of word remaining..
	 //n is alphabets size and constraint is the constraint,if any on the first alphabet to be inserted here(default=0)
	if(constraint>n)                    //no constraint will satisfy
    	return 0;
	
   if(table[m][constraint]!=-1)                 //already evaluated
		return table[m][constraint];
  //  cout<<"m:"<<m<<" n:"<<n<<" constraint:"<<constraint<<endl;
    long result;int i;
    result=0;
    if(m==1)
	{
        if(constraint==1||constraint<=n/2)             //no constraints or it doesnt matter
			result=n-(n/2);
		else                               // constraint>n/2
	        result=n-constraint+1;
	}
	else
	{
		if(constraint==1)							 //no constraint
		{  
		     //pick any letter for this position
			  for(i=1;i<n+1;i++)                       //REMEMBER:COLUMN 0 corresponds to no constraint..not first letter!
			  {
	//		  cout<<"considering "<<i<<endl;
			   
			  //i.e we are picking letter at column i here
                if(2*i>n)
                	result+=find_words(m-1,n,1,table);
                else
                    result+=find_words(m-1,n,2*i,table);  //set constraint
			  }
		}
		else
		{
             for(i=constraint;i<n+1;i++)
             {//cout<<"considering "<<i<<endl;
			  	
             	if(2*i>n)
             		result+=find_words(m-1,n,1,table);
             	else
             		result+=find_words(m-1,n,2*i,table);
             }
		}
	}
  table[m][constraint]=result;                //store result
 // cout<<"retuning for m:"<<m<<" n:"<<n<<" result:"<<result<<endl;
  return result;
}

int main()
{
	int t,i;
	cin>>t;
	for(i=0;i<t;i++)
	{
		int n,m,j,k;
		cin>>n>>m;
		vector<vector<long> > table;   //a table of size (m+1)*(n+1) representing m*(constrant) including value 0 for both dimensions.
	    table.resize(m+1);
	    for(j=0;j<m+1;j++)
	    	table[j].resize(n+1);
        for(j=0;j<m+1;j++)
        	for(k=0;k<n+1;k++)
        		table[j][k]=-1;             //simply initialize with -1;
	    cout<<find_words(m,n,1,table)%100000007<<endl;
	}
	return 0;
}