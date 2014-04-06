
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

class PrimeSoccer{

public:
   long long int fact(int n)
  {
    if(n==0) return 1;
    if (n>0) return n*fact(n-1);
  }

   long long int NCR(int n,int r)
   {
    if(n==r) return 1;
    if (r==0&&n!=0) return 1;
    else return (n*fact(n-1))/fact(n-1)*fact(n-r);
   }

   long long int find_prob(int s_a, int s_b,int i)
   {
     cout<<NCR(18,i)<<endl;
     long long int pro_a=(NCR(18,i))*(pow(s_a,i))*(pow((1-s_a),18-i));
     cout<<"pro_A"<<pro_a<<endl;
     long long int pro_b=(NCR(18,i))*(pow(s_b,i))*(pow((1-s_b),18-i));
     cout<<"pro_B"<<pro_b<<endl;
     long long int pro=pro_a+pro_b-(pro_a*pro_b);
     cout<<"prob"<<pro<<endl;
     return pro;
   }

   long long int getProbability(int skillTeamA, int skillTeamB)
   { int s_a=skillTeamA;
     int s_b=skillTeamB;
     long long int ans=0;
     int prime[]={2,3,5,7,11,13,17};
     for(int i=0;i<7;i++)
       {
        ans+=find_prob(s_a,s_b,i);
        cout<<"ans"<<ans<<endl;
        cout<<endl;
       }
     return ans;
   }

};

int main()
{
   int skillTeamA=50;
   int skillTeamB=50;
   PrimeSoccer obj;
   cout<<obj.getProbability(skillTeamA,skillTeamB);
   return 0;
}
