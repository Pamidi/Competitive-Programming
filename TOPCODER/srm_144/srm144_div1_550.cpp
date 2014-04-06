#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

struct rule
{
   string message;
   int choices;
   int blanks;
   char sorted;
   char unique;
   long long int tickets;
};

bool cmp_by_tickets(const rule& a,const rule& b)
{
   return a.tickets<b.tickets;
}

int summation(int i)
{
  return (i*(i+1))/2;
}

long long int find_ways(int local_choices,int blanks)
{
  long long int answer=0,innerloop=0;
  if(blanks==0)
    return 0;
  if(blanks==1)
    return local_choices;
  if(blanks==2)
    return summation(local_choices);
   for(int i=1;i<local_choices;i++)
   {
    if(blanks==3)
      innerloop+=summation(i);
    else
      innerloop+=find_ways(i,blanks-1);
   }
   answer=innerloop;
   return answer;
}


class Lottery 
{
public:
	vector <string> sortByOdds(vector <string> rules) 
	{
        vector<rule> game_rules(rules.size());

        for(int i=0;i<rules.size();i++)
        {
        	stringstream oup;
          oup<<rules[i];
        	getline(oup,game_rules[i].message,':');
          oup>>game_rules[i].choices>>game_rules[i].blanks>>game_rules[i].sorted>>game_rules[i].unique;  
            
            long long int out;
            if(game_rules[i].sorted=='F'&&game_rules[i].unique=='F')
            {
               out=1; 
               int k=game_rules[i].blanks;
               while(k--)
               	out*=game_rules[i].choices;
            }
            if(game_rules[i].sorted=='T'&&game_rules[i].unique=='F')
               out=find_ways(game_rules[i].choices,game_rules[i].blanks);
            if(game_rules[i].sorted=='F'&&game_rules[i].unique=='T')
            {
               out=1;
               int k=game_rules[i].choices;
               int w=game_rules[i].blanks;
               while(w--)
                out*=k--;
            }
            if(game_rules[i].sorted=='T'&&game_rules[i].unique=='T')
               out=summation(game_rules[i].choices-game_rules[i].blanks+1);
            game_rules[i].tickets=out;
        }	   	

        sort(game_rules.begin(),game_rules.end(),cmp_by_tickets);
        vector<string> output;
        for(int i=0;i<game_rules.size();i++)
          output.push_back(game_rules[i].message);
        return output;
	}
};

int main()
{
      vector<string> rules;
      rules.push_back("PICK ANY TWO: 10 2 F F");
      rules.push_back("PICK TWO IN ORDER: 10 2 T F");
      rules.push_back("PICK TWO DIFFERENT: 10 2 F T");
      rules.push_back("PICK TWO LIMITED: 10 2 T T");
      Lottery obj;
      vector<string> output;
      output=obj.sortByOdds(rules);
      for(int i=0;i<output.size();i++)
        cout<<output[i]<<endl;
      return 0;
}