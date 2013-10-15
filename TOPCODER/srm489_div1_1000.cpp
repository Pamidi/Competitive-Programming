#include <iostream>
using namespace std;
#include <vector>
#include <cstdlib>
#include <limits.h>
#include <algorithm>

int factorial(int n)
{
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

long long int find_count(int j,int n,vector<int> r,int prev_dist)
{
   unsigned int i;
  // cout<<"j:"<<j<<" "<<"n:"<<n<<endl;
    
    if (n>j)                         //more trees
        return 0;
        
    if(j==1&&n==1)
        {
        if(prev_dist==0||r[0]<=prev_dist)
        return 1;
        if(r[0]>prev_dist)
        return 0;
        }                    //success
    if(j>1&&n==1)
    {
        if(prev_dist==0||r[0]<=prev_dist)
            return j;
        else return find_count(--j,n,r,prev_dist+1);
    }
    long long temp_sum=0;
    for(i=0;i<r.size();i++)              //considering all trees for jth position
    {   if(prev_dist==0||r[i]<=prev_dist)
           {
            vector<int> temp(r.begin(),r.end());    //temporary vector
            vector<int>::iterator it=find(temp.begin(),temp.end(),r[i]);
            temp.erase(it);                         //remove that tree from list
            temp_sum+=find_count(j-r[i],n-1,temp,r[i]);
           }
    }
    if(prev_dist==0)
        temp_sum+=find_count(j-1,n,r,prev_dist);
    else
        temp_sum+=find_count(j-1,n,r,prev_dist+1); //not considering that candidate
    return temp_sum;               //return answer
}


class AppleTrees
{
public:
    long long int theCount(int D,vector<int> r);
};

long long int AppleTrees::theCount(int D,vector<int> r)
{
    int i,j,k,n;
    n=r.size();                           //number of trees to be planted
    return find_count(D,n,r,0);
}

int main()
{
  int D=47;
  int temp[]={4,8,9};
  vector<int> r(temp,temp+sizeof(temp)/sizeof(temp[0]));
  AppleTrees obj;
  cout<<obj.theCount(D,r)%1000000007;
  return 0;
}
