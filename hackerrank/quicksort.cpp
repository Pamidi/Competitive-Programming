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

int partition(vector<int> &a,int start,int end)
{
	int left=start,right=end;
	int key=a[start];
    while((left<right))
    {
        while(a[left]<=key)
        	left++;
        while(a[right]>key)
        	right++;
        if((left<right)&&(left<=end)&&(right>=start))
        {
        	int temp=a[left];
        	a[left]=a[right];
        	a[right]=temp;
        }
    }
    a[start]=a[right];
    a[right]=key;
    return right;
}


void quickmain(vector<int> &ar,int start,int end)
{
	if(start>=end)
       return;
	int n=ar.size();
	int pos=partition(ar,start,end);       //partition on the basis of the first element
    for(int i=start;i<=end;i++)
    	cout<<ar[i]<<" ";
    cout<<endl;
    quickmain(ar,start,pos-1);
    quickmain(ar,pos+1,end);
    cout<<endl;
}

void quickSort(vector <int>  ar, int ar_size) 
{
  quickmain(ar,0,ar_size-1);
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

quickSort(_ar, _ar_size);
   
   return 0;
}