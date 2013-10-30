#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <cstdlib>

int find_min(vector<int> v,int &found,int step)
{

    if(found==1)
    	return INT_MAX;
    int n=v.size();
	sort(v.begin(),v.end());
    vector<int> v1(v.begin(),v.end());
    vector<int> v2(v.begin(),v.end());
    vector<int> v3(v.begin(),v.end());
    
    int i,start=v[0];
    for(int i;i<n;i++)
    	if(v[i]!=start)
            break;
    if(i==n)
    {
    	found=1;
    	return step;
    }

    for(int i=0;i<n-1;i++)
    {    
      v1[i]+=1;
      v2[i]+=2;
      v3[i]+=5;
    }
    int k1,k2,k3;
    k1=find_min(v1,found,++step);
    k2=find_min(v2,found,++step);
    k3=find_min(v3,found,++step);
    return min(k1,min(k2,k3));

}

int main()
{
	int t,i;
	cin>>t;
	for(i=0;i<t;i++)
	{
		int n,j;
		cin>>n;
		vector<int> v(n);
		for(j=0;j<n;j++)
			cin>>v[j];
		int found=0;
		if(v.size()==0||v.size()==1)
			cout<<"0"<<endl;
		else
		cout<<find_min(v,found,0)<<endl;
	}
	return 0;
}