#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<sstream>
using namespace std;
long long calc_insertionsort_count(vector<long long> a)
{
    if(a.size()==1) return 0;
   long long i,j,r,count=0;
    for(i=1;i<a.size();i++)
    {
        r=a[i];
        for(j=i-1;j>=0;j--)
        {
        if(r>=a[j])
        break;
        count++;
        a[j+1]=a[j];
        }
        a[j+1]=r;
    }
    return count;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long long T;
    cin>>T;
    long long res[T],N,temp,i=0;
    string s;
    vector<long long> a;
    while(i<T)
    {   a.clear();
        cin>>N;
        cin.ignore();
        getline(cin,s);
        stringstream out;
        out<<s;
        while(out>>temp)
            a.push_back(temp);
        res[i]=calc_insertionsort_count(a);
        i++;
        out.str("");
    }
    for(i=0;i<T;i++)
        cout<<res[i]<<endl;
    return 0;
}
