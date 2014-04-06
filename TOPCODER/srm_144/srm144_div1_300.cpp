#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;

template<typename T1,typename T2>
T1  convert(T2 d)
{
    stringstream out;
    out<<d;
    T1 e;
    out>>e;
    return e;
}

int ci(char c)
{
    return convert<int>(c);
}
char cc(int c)
{
    return convert<char>(c);
}
    
vector<string> decode(string message)
{
        vector<string> output;
        for(int i=0;i<2;i++)
        {
            string temp="";
            temp+=(i==0?'0':'1');          //first character
            int j;
            bool fail=false;
         //   cout<<"temp:"<<temp<<endl;
            for(j=0;j<message.length()-1;j++)
            {
                char c;
                if(j==0)
                    c=cc(ci(message[0])-ci(temp[0]));
                else
                 c=cc(ci(message[j])-ci(temp[j])-ci(temp[j-1]));
              //  cout<<"c:"<<c<<endl;
                if(c!='0'&&c!='1')     //invalid binary digit
                {
                    fail=true;
                    break;
                }
                else
                    temp+=c;
            }
            if(!fail&&(ci(message[j])==ci(temp[j])+ci(temp[j-1])))
                output.push_back(temp);
            else
                output.push_back("NONE");
        }
    return output;
};

int main()
{
    vector<string> output;
    output=decode("22111");
    for(int i=0;i<2;i++)
       cout<<output[i]<<endl;
    return 0;   
}   