#include <iostream>
using namespace std;
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <limits.h>
#include <float.h>

int main()
{
int n;
cin>>n;
double max_area=0,min_area=DBL_MAX;
int max_index=1,min_index=1;

for(int i=0;i<n;i++)
{
  int x1,x2,x3,y1,y2,y3;
  cin>>x1>>y1>>x2>>y2>>x3>>y3;
  double area=0.5*abs((x1*y2-x1*y3+x2*y3-x2*y1+x3*y1-x3*y2));
  if(area>=max_area)
   {
      max_area=area;
      max_index=i+1;
   }
  if(area<=min_area)
  {
     min_area=area;
     min_index=i+1;
  }
}
  cout<<min_index<<" "<<max_index<<endl;

}
