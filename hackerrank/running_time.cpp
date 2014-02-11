#include <iostream>
using namespace std;
#include <cstdlib>
#include <algorithm>
#include <vector>

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	int nos=0;
	for(int i=1;i<n;i++)       //start inserting from second element
	{
         //insert a[i] into appropriate place
		 int key=a[i];
		 int temp=i-1;
		 while(key<a[temp]&&temp>=0)
		 {
		   a[temp+1]=a[temp];
           temp--;
		 }
		 //insert in temp+1 position
		 //shift every element from temp+1 to i-1
		 nos+=i-1-temp;
		 a[temp+1]=key;
	}
	cout<<nos<<endl;
   }
	return 0;
}