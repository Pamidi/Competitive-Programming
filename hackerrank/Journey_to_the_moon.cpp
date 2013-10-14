#include <vector>
#include <iostream>
#include<cstring>
#include<unordered_map>
#include<list>
using namespace std;


int main() {
    long long N,l,temp,i,j,z,a,b;
    vector<list<long long>> my_list;
    list<long long>::iterator list_it;
    unordered_map<long long,bool> hash;          //to check if its part of any list
    unordered_map<long long,long long> find_list_index;   //to find the list number in my_list
    cin>>N>>l;

    for(i=0;i<N;i++)
        hash[i]=false;
    for(i=0;i<N;i++)
        find_list_index[i]=-1;
    for(i=0;i<l;i++)
    {
        cin>>a>>b;
        if(!hash[a]&&!hash[b])
        {
            list<long long> temp;
            temp.push_back(a);
            temp.push_back(b);
            hash[a]=hash[b]=true;
            my_list.push_back(temp);
            find_list_index[a]=find_list_index[b]=my_list.size()-1;
        }
        else if(hash[a]&&hash[b])
        {
            list<long long> temp1,temp2,last;
            temp1=my_list[find_list_index[a]];
            temp2=my_list[find_list_index[b]];
            my_list.erase(my_list.begin()+find_list_index[a]);
            my_list.erase(my_list.begin()+find_list_index[b]);
            for(list_it=temp2.begin();list_it!=temp2.end();list_it++)
                temp1.push_back(*list_it);
            my_list.push_back(temp1);
            last=my_list[my_list.size()-1];
            for(list_it=last.begin();list_it!=last.end();list_it++)
                find_list_index[*list_it]=my_list.size()-1;
        }
        else if(hash[a])
        {   hash[b]=true;
            my_list[find_list_index[a]].push_back(b);
            find_list_index[b]=find_list_index[a];
        }
        else
        {   hash[a]=true;
            my_list[find_list_index[b]].push_back(a);
            find_list_index[a]=find_list_index[b];
        }

    }
    cout<<"\n\n";
    for(i=0;i<my_list.size();i++)
    {
       list<long long> temp;
       temp=my_list[i];
       for(list_it=temp.begin();list_it!=temp.end();list_it++)
           cout<<*list_it<<" ";
       cout<<endl;
    }

    //end of reading ..now to calculate combinations.
    long long ans=0;
    if(N==0||N==1||N==2)
        cout<<4-4;
    else
    {
    for(i=0;i<my_list.size();i++)
    {
        for(j=i+1;j<my_list.size();j++)
            ans+=my_list[i].size()*my_list[j].size();
    }

    cout<<ans;
    }
    return 0;
}
