#include <iostream>
using namespace std;
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>

class SRMCards
{
public:
	int maxTurns(vector<int>);
};

int SRMCards::maxTurns(vector<int> cards)
{
	sort(cards.begin(),cards.end());
	int count=0;
	if(cards.size()==1)
      return 1;
    bool last_select=false;
	for(int i=0;i<cards.size()-1;)
	{
		if(cards[i+1]==cards[i]+1)
		{
			i+=2;
			if(i+1==cards.size()-1)
				last_select=true;
	    }
	    else
	    	i+=1;
	    count++;
	}
	if(!last_select)
		count++;
return count;
}

int main()
{
	int a[]={10, 11, 12, 13, 14, 1, 2, 3, 4, 5, 6, 7, 8, 9}
;
;
	vector<int> cards(a,a+sizeof(a)/sizeof(a[0]));
	SRMCards obj;
	cout<<obj.maxTurns(cards);
	return 0;
}