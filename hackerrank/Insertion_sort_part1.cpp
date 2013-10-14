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
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
/* Head ends here */
void insertionSort(vector <int>  ar) {

if(ar.size()==1) return;
    int i;
    int v=ar[ar.size()-1];
    i=ar.size()-2;
    while(i>=0)
    {
        if(v>=ar[i])
            break;
        ar[i+1]=ar[i--];
            for(int j=0;j<ar.size();j++)
            cout<<ar[j]<<" ";
        cout<<endl;
    
    }
    ar[i+1]=v;
    for(int j=0;j<ar.size();j++)
        cout<<ar[j]<<" ";
}

   
/* Tail starts here */
int main(void) {
    
   vector <int>  _ar;
   int _ar_size;
cin >> _ar_size;
for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
   int _ar_tmp;
   cin >> _ar_tmp;
   _ar.push_back(_ar_tmp); 
}

insertionSort(_ar);
   
   return 0;
}