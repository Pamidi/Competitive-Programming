#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
/* Head ends here */
int lonelyinteger(vector < int > a) 
{
    unordered_map<int,int> int_map;
    for(int i=0;i<=100;i++)
        int_map[i]=0;
   for(int i=0;i<a.size();i++)
   {
      int_map[a[i]]++;
   }
   for(int i=0;i<=100;i++)
     if(int_map[i]==1)
        return i;
   return 0; 

}
/* Tail starts here */
int main() {
    int res;
    
    int _a_size;
    cin >> _a_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _a;
    int _a_item;
    for(int _a_i=0; _a_i<_a_size; _a_i++) {
        cin >> _a_item;
        _a.push_back(_a_item);
    }
    
    res = lonelyinteger(_a);
    cout << res;
    
    return 0;
}