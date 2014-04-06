#include <iostream>
using namespace std;
#include <cstdlib>
#include <algorithm>
#include <vector>

class NumberoffibCalls
{
public:
	vector<int> fibocalls(int n)
	{
		vector<int> no_0(n+1),no_1(n+1);
		no_1[0]=0;no_1[1]=1;no_1[2]=1;
		no_0[0]=1;no_0[1]=0;no_0[2]=1;
		for(int i=3;i<=n;i++)
		{
           no_0[i]=no_0[i-1]+no_0[i-2];
           no_1[i]=no_1[i-1]+no_1[i-2];
        }
        vector<int> out;
        out.push_back(no_0[n]);
        out.push_back(no_1[n]);
        return out;
	}
};

int main()
{
	NumberoffibCalls obj;
	vector<int> out=obj.fibocalls(22);
	cout<<"{"<<out[0]<<","<<out[1]<<"}"<<endl;
	return 0;
}