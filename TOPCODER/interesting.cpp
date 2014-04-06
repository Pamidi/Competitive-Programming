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
#include <unordered_map>

using namespace std;


class InterestingNumber {
public:
	string isInteresting(string x)
    {
	   unordered_map<int,int> map,first_map,second_map;
	   for(int i=0;i<x.length();i++)
	   {
	       map[x[i]-48]++;
	       if(map[x[i]-48]==1)
	       	  first_map[x[i]-48]=i;
	       else 
	       	  second_map[x[i]-48]=i;
	   }
	   bool flag=false;
	   for(int i=0;i<=9;i++)
	   {
	   	  if(map[i]==0) 
	   	     continue;
          if(i!=second_map[i]-first_map[i]-1)
          {
          	flag=true;
            break;
          }
	  }
	  if(flag)
	     return "Not interesting";
	  else
	     return "Interesting";	
	}
};

int main()
{
	InterestingNumber obj;
	cout<<obj.isInteresting("2001");
}