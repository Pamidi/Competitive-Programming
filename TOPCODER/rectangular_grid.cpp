#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class RectangularGrid {
public:
    long long find_fitting_rectangles(int width,int height,int x,int y)
    {
    	return (width-x+1)*(height-y+1);
    }

	long long countRectangles(int width, int height)
	{
		long long out=0;
	    for(int i=1;i<=width;i++)
	      for(int j=1;j<=height;j++)
             	//for all rectangles of dimension i*j
                if(i!=j)
                	out+=find_fitting_rectangles(width,height,i,j);
        return out;
	}
};
