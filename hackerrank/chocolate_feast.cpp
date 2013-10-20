#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main()
{
int T;
cin>>T;
for(int i=0;i<T;i++)
{
	int N,C,M;
	cin>>N>>C>>M;

	int initial=N/C;
	if(initial<M)
		cout<<initial<<endl;
	else
	{
		int cur_candy=initial;
		while(cur_candy>=M)
		{
             cur_candy=cur_candy-M+1;
             initial++;
		}
		cout<<initial<<endl;
	}
}
return 0;
}
