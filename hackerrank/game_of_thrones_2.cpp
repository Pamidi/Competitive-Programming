#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <limits.h>
#include <string>
#include <unordered_map>

//number of anagrams which are palindromes %10^9+7
typedef long long int lli;
const lli mod=1000000007;

lli comb(long n,long r)
{
	//for finding nCr

}
int main()
{
   string s;
   getline(cin,s);
   long k=s.length();
   unordered_map<char,long> hash;
   	  hash[s[i]]++;

   long spots=k/2;
   lli ang=1;
   bool odd_flag=k%2==0?false:true;
   for(int i=0;i<26;i++)
   {
   	  char c=97+i;
   	  if(odd_flag&&hash[c]%2==1)
   	  	 continue;
   	  long m=hash[c]/2;
   	  ang*=(comb(spots,m)%mod;             //find combinations of putting it..
   	  spots-=m;
   }
   cout<<ang<<endl;
}