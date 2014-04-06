#include <iostream>
using namespace std;
#include <cstdlib>
#include <algorithm>
#include <vector>

class AdvertisingAgency
{
public:
     int numberOfRejections(vector<int> requests)
     {
        vector<int> billboard(100);
        fill(billboard.begin(),billboard.end(),0);
        int rej=0;
        for(int i=0;i<requests.size();i++)
        {
          if(billboard[requests[i]-1]==1)
              rej++;
          else
           billboard[requests[i]-1]=1; 
        }
        return rej;
     }
};

int main()
{
	int a[]=	   	
{100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100
};
	vector<int> requests(a,a+sizeof(a)/sizeof(a[0]));
	AdvertisingAgency obj;
	cout<<obj.numberOfRejections(requests)<<endl;
	return 0;
}