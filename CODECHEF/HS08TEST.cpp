#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
  long x;
	double y;
	cin>>x>>y;
	if(x%5==0 && x+0.50<y && x >0 && x <=2000 && y>=0 && y <=2000 ) cout <<fixed<<setprecision(2)<<y-(x+0.50);
	else cout<<fixed<<setprecision(2)<<y;
	return 0;
}
