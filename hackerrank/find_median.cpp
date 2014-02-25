#include <iostream>
using namespace std;
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>

int find_median(vector<int> &ar,int p,int q,int k)
{
	//k is the index of median
	//first partition using qth element as pivot
	if(p==q)
		return ar[q];
	int i,j=p-1;
	int key=ar[q];
	for(int i=p;i<=q;i++)
	{
       if(ar[i]<key)
       {
       	j++;
       	int temp=ar[j];
       	ar[j]=ar[i];
       	ar[i]=temp;
       } 
	} 
	j++;
	ar[j]=key;
    if(j==k)
    	return key;
    else if(k<j)
    	return find_median(ar,p,j,k);
    else
    	return find_median(ar,j+1,q,k-j+1);
}

int main()
{
	long long int n;
	cin>>n;
	vector<int> ar(n);
	for(long long int i=0;i<n;i++)
		cin>>ar[i];
	cout<<find_median(ar,0,n-1,n/2);

}