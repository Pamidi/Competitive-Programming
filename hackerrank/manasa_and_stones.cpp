#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <unordered_map>

/*to find ax+by
x+y=n;
*/

void print_numbers(int n,int a,int b,int cur)
{
   unordered_map<int,int> mymap;
   vector<int> v;
   n--;
   for(int i=1;i<=n;i++)        //for x
   {
	  int j=n-i;
	  ifnt temp=(a*(i-1))+(b*j);
	  if(mymap[temp]==0)
	  {
	  	 mymap[temp]=1;
	  	 v.push_back(temp);
	  }
   }
   sort(v.begin(),v.end());
   int k=v.size();
   for(int i=0;i<k;i++)
   	  cout<<v[i]<<" ";
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,a,b;
		cin>>n>>a>>b;
		print_numbers(n,a,b,0);
		cout<<endl;
	}
}