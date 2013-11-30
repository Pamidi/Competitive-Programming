#include <iostream>
using namespace std;
#include <cstdlib>
#include <vector>
#include <algorithm>

int main()
{
	int N,T,temp,i,j,l;
	cin>>N>>T;
	vector<int> width;
	for(i=0;i<N;i++)
	{
        cin>>temp;
        width.push_back(temp);
	}
    

	for(int m=0;m<T;m++)
	{
	   int min=3;
	   cin>>i>>j;
	   for(int k=i;k<=j;k++)
	   	  if(width[k]<min)
	   	  	min=width[k];
	   cout<<min<<endl;
	}
	return 0;
}