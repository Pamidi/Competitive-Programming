#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int find_similarity(char *input_string,char *suffix_string)
{
	int res=0;
	char* input_copy=input_string;
	char* suffix_copy=suffix_string;
	//cout<<"loop:"<<endl<<"input:"<<*input_copy<<endl<<"suffix:"<<*suffix_copy<<endl;
    if(!*input_string||!*suffix_string)
    	return 0;
    while((*input_copy&&*suffix_copy)&&(*input_copy==*suffix_copy))
    {
    	     res++;
             input_copy++;suffix_copy++;
    //       cout<<"update_input:"<<*input_copy<<endl<<"update_suffix:"<<*suffix_copy<<endl;
    }
    //cout<<"res:"<<res<<endl;
   // cout<<"input_string:"<<*input_string<<endl<<"suffix_string:"<<*suffix_string<<endl;
    res+=find_similarity(input_string,++suffix_string);
    return res;
}


int main()
{
	int t;
    cin>>t;
    cin.ignore();
    while(t>0)
    {   string input;
    	getline(cin,input);
    	int result=find_similarity(&input[0],&input[0]);
    	cout<<result<<endl;
    	t--;
    }
}