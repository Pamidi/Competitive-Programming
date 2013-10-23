#include <iostream>
using namespace std;
#include <vector>

int main()
{
	int t,i;
	cin>>t;
	for(i=0;i<t;i++)
	{
         long long m,n,j; 
         cin>>m>>n;
         vector<bool> check(n-m+1);
         for(j=0;j<n-m+1;j++)
         	check[j]=false;
         for(j=m;j<=n;j++)
         {
         	int z;
         	if(check[j-m]==false)
         		cout<<j<<endl;
         	for(z=j;z<=n;z+=j)
         	{
               check[z-m]=true;   //visited
         	}
         }
	}
	return 0;
}