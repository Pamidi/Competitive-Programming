#include <iostream>
using namespace std;
#include <vector>
#include <sstream>
#include <cstdlib>
class BinaryCode {
public:
    vector<string> decode(string);
};

vector<string> BinaryCode::decode(string message) //p is original
{
vector<string> result;
if(message.length()==1)
  {
    if(message=="0")
    {result.push_back("0");
     result.push_back("NONE");
    }
    else if(message=="1")
    {
        result.push_back("NONE");
        result.push_back("1");
    }
    else
    {
        result.push_back("NONE");
        result.push_back("NONE");
    }
    return result;
  }

for(int i=0;i<=1;i++)
{
    int found=0;
    string p="";
    if(i==0) p+='0';
    else     p+='1';
    int j;
    for(j=1;j<message.length();j++)
    {   int bit;
        string temp1="",temp2="",temp3="";
        temp1+=message[j-1];
        temp2+=p[j-1];
        if(j==1)
        {   bit=atoi(temp1.c_str())-atoi(temp2.c_str());

        }
        else
           {
            temp3+=p[j-2];
            bit=atoi(temp1.c_str())-atoi(temp2.c_str())-atoi(temp3.c_str());
           }
        if(bit==0||bit==1)
        {
            stringstream ss;string tempout;
            ss<<bit;
            ss>>tempout;
            p.append(tempout);

           }
        else
        {
            result.push_back("NONE");
            found=1;
            break;
        }
    }
    if(found==1)
        continue;

    string temp1="",temp2="",temp3="";
    temp1=message[j-1];
    temp2=p[j-1];
    temp3=p[j-2];
    if(atoi(temp1.c_str())==atoi(temp2.c_str())+atoi(temp3.c_str()))
        result.push_back(p);
    else
        result.push_back("NONE");
}
return result;
}