#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <cstdlib>
using namespace std;

vector<string> explode(string s, char delim)
{
    vector<string> result;
    stringstream iss(s);
    for(string token;getline(iss,token,delim);)
    {
        result.push_back(token);
    }
    return result;
}

long long int find_combinations(int choices,int blanks,string unique)
{
    long long int temp=0;

    if(blanks>choices&&unique=="T") return 0;

    if(blanks==2)
    {
        if(unique=="F")
        {
            return choices*(choices+1)/2;
        }
        else if(unique=="T")
        {
            return (choices-1)*(choices)/2;
        }
    }
    else
    {
        for(int i=1;i<=choices;i++)
        {   if(unique=="F")
            temp+=find_combinations(choices+1-i,blanks-1,unique);
            else
            temp+=find_combinations(choices-i,blanks-1,unique);
        }
    }
    return temp;
}

class Lottery {
public:
    vector <string> sortByOdds(vector <string> rules)
    {
        vector<string> title;     //to store just the names...
        vector<string> result;
        map<long long int,int> mymap;
        for(int i=0;i<rules.size();i++)
        {
            //get a list of probablities in the same order as input.
            //for each row,extract parts;
            vector<string> split1,split2;
            string name,sorted,unique;
            int choices,blanks;
            split1=explode(rules[i],':');
            split2=explode(split1[1],' ');
            name=split1[0];
            title.push_back(name);
            sorted=split2[3];
            unique=split2[4];
            choices=atoi(split2[1].c_str());
            blanks=atoi(split2[2].c_str());
            long long int combinat=1;
            if(sorted=="T")
            {
                if(unique=="T")
                {
                    combinat=find_combinations(choices,blanks,unique);

                }
                else if(unique=="F")
                {
                    combinat=find_combinations(choices,blanks,unique);  //problem
                    exit(0);
                }
            }
            else if(sorted=="F")
            {
                if(unique=="T")
                {
                    if(choices<blanks)
                      combinat=0;
                    else
                    while(blanks>0)
                    {
                        combinat*=choices;
                        choices--;blanks--;
                    }
                }
                else if(unique=="F")
                {
                    while(blanks>0)
                    {
                        combinat*=choices;
                        blanks--;
                    }
                }
            }
            mymap.insert(pair<long long int,int>(combinat,i));
        }

        //process combinations list here
        for(map<long long int,int>::iterator it=mymap.begin();it!=mymap.end();++it)
           result.push_back(title[it->second]);


        return result;

    }
};

int main()
{
    Lottery a;
    vector<string> input,output;
    input.push_back("INDIGO: 93 8 T F");
     input.push_back("ORANGE: 29 8 F T");
     input.push_back("VIOLET: 76 6 F F");
     input.push_back("BLUE: 100 8 T T");
     input.push_back("RED: 99 8 T T");
     input.push_back("GREEN: 78 6 F T");
     input.push_back("YELLOW: 75 6 F F");
     output=a.sortByOdds(input);
    for(int i=0;i<output.size();i++)
        cout<<output[i]<<endl;
    return 0;
}
