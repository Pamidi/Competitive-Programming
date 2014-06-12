#include <iostream>
using namespace std;
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <string>

typedef long long int lli;

lli add_score(vector<lli> &a,long i,long n)
{
	lli sum=0;
	for(long j=0;j<n;j++)
		sum+=a[i+j];
	return sum;
}
long opponent_best_selection(vector<lli> &c,long i,int my_pick)
{
	//chooses the optimal pick for the opponent if my selection is my_pick(i.e 1,2 or 3)
	long n=c.size()-1;
	vector<lli> options(4);
	if(i+my_pick<=n)  options[1]=c[i+my_pick+1];
    if(i+my_pick+1<=n)  options[2]=c[i+my_pick+2];
    if(i+my_pick+2<=n)  options[3]=c[i+my_pick+3];
    int opp_choose_case=max_element(options.begin(),options.end())-options.begin();
    
    return opp_choose_case;        
}

lli find_max_score_for_pick(vector<lli> &c,vector<lli> &a,long i,int pick)
{
	        lli maxscore;
	        cout<<"my best pick:"<<pick<<endl;
	        int k=opponent_best_selection(c,i,pick);
	        long n=c.size()-1;
            if(i+pick+k<=n)
               maxscore=c[i+pick+k]+add_score(a,i,pick);
            else
               maxscore=add_score(a,i,pick);
            cout<<"his best pick:"<<k<<endl;
            cout<<"picking "<<i<<" score :"<<maxscore<<endl;
            return maxscore;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long n;
		cin>>n;
		vector<lli> a(n+1);
		for(long i=1;i<=n;i++)
			 cin>>a[i];

	    //c[i] defines maximum score current player can get with i..n bricks remaining
	    vector<lli> c(n+1);
	    c[0]=0;
	    if(n>=1) c[n]=a[n];
	    if(n>=2) c[n-1]=a[n-1]+a[n];
        if(n>=3) c[n-2]=a[n-2]+a[n-1]+a[n];
	    
	    for(long i=n-3;i>=1;i--)
	    {
            //consider me picking 1 ,2 or 3 and return maximum.
            cout<<"KINGDOM OF "<<i<<" :"<<endl;
            c[i]=0;
            for(int j=1;j<=3;j++)
            	c[i]=max(c[i],find_max_score_for_pick(c,a,i,j));
            cout<<"c["<<i<<"] :"<<c[i]<<endl<<endl;;
        }
	    cout<<c[1]<<endl;
	}
}