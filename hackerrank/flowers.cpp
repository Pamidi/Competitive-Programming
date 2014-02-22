/* Sample program illustrating input/output */
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int main(void)
{

//Helpers for input and output

   int N, K;
   cin >> N >> K;
    vector<long long int> C(N);
   for(int i = 0; i < N; i++){
      cin >> C[i];
   }
   long long int result=0;
   if(N<=K)
   {
   	result=accumulate(C.begin(),C.end(),result);
   }
   else
   {
   	sort(C.begin(),C.end(),greater<int>());
   	int x=0;
   	int count=0;
   	for(int i=0;i<C.size();i++)
   	{
   		result+=(x+1)*C[i];
   		count++;
   		if(count==K)
   		{	
   			count=0;
   			x++;
   	    }
   	}
   }
   cout << result << "\n";
   
   return 0;
}