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


class Time {
public:
	string whatTime(int seconds)
    {
       int hour=seconds/3600;
       int min=(seconds-3600*hour)/60;
       int sec=(seconds-3600*hour-60*min);
       stringstream s;
       string out;
       s<<hour<<":"<<min<<":"<<sec;
       s>>out;
       return out;
   }
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!