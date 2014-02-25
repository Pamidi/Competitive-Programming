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

typedef long long int LLI;

class Time
{
public:
 string whatTime(int seconds)
 {
   int hours=(seconds/3600);
   int minutes=(seconds-hours*3600)/60;
   int second=(seconds-hours*3600-minutes*60);
   stringstream out;
   out<<hours<<":"<<minutes<<":"<<second;
   return out.str();
 }
};

