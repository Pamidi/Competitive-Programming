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

int max_height,distance_tot;
int land_size;


class HillHike {
public:
    long long findpath(int c[][][],vector<int> &landmarks,int r,int h,int t,int touched)
    {
        if(c[r][h][t][touched]!=INT_MAX)
            return c[r][h][t][touched];
        if(landmarks[t]==h)
              t++;
        if(h<0||h>max_height) return 0;
        if(h==0&&r==0&&t==land_size&&touched)

    }
	long long numPaths(int distance, int maxHeight, vector <int> landmarks) 
	{
        int c[distance+1][maxHeight+1][landmarks.size()+1][2];
        for(int i=0;i<distance+1;i++)
            for(int j=0;j<maxHeight+1;j++)
                for(int k=0;k<landmarks.size()+1;k++)
                    for(int z=0;z<2;z++)
                        c[i][j][k][z]=INT_MAX;
        max_height=maxHeight;
        distance_tot=distance;
        land_size=landmarks.size();
        return findpath(c,landmarks,distance,0,0,0);
    }
};

int main()
{
    HillHike obj;
    int a[]={2,2};
    vector<int> landmarks(a,a+sizeof(a)/sizeof(a[0]));
    cout<<obj.numPaths(5,2,landmarks);
    return 0;
} 