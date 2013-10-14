#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<cstring>
#include<sstream>
using namespace std;

void insertionSort(vector<int> ar)
{
    int i,j,temp,dup;
    if(ar.size()==1) return;
    for(i=1;i<ar.size();i++)
    {   int dup=ar[i];
        for(j=i-1;j>=0;j--)
        {
            if(dup>=ar[j])
                break;
            ar[j+1]=ar[j];
        }
        ar[j+1]=dup;
        for(temp=0;temp<ar.size();temp++)
           cout<<ar[temp]<<" ";
        cout<<endl;  
    }
    
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int s,temp;
    vector<int> ar;
     cin>>s;
    cin.ignore();
    string st;
    getline(cin,st);
    stringstream out;
    out<<st;
    while(out>>temp)
        ar.push_back(temp);
    
    insertionSort(ar);
    
    return 0;
}
