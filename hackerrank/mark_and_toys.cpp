#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<cstring>
#include<sstream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    long long temp,K,count;
    string s,nums;
    getline(cin,s);
    stringstream out,numst;
    out<<s;
    out>>N>>K;
    vector<long long> a(N);
    getline(cin,nums);

    numst<<nums;
    vector<long long>::iterator it=a.begin();
     while(numst>>temp)
    *it++=temp;
    sort(a.begin(),a.end());
    temp=0;

    it=a.begin();
    while(it!=a.end()&K>0)
    {
       if(K<*it)break;
        K-=*it++;
        temp++;
    }
    cout<<temp;
    return 0;
}
