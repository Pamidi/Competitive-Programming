#!/usr/bin/py
from collections import Counter

mod = 10**9 + 7

def hasPalindrome(word):
    x = Counter(word)
    count = 0
    for i in x:
        if x[i]%2!=0:
            count += 1

    if count > 1:
        return False
    else:
        return True

def getfactmod(b):
    val = 1
    for i in range(1,b):
        val =((val%mod)*((i+1)%mod))%mod

    return val

def getpowermod(a,b):
    if b == 0:
        return 1
    if b == 1:
        return a
    temp = getpowermod(a,b/2)
    if b%2==0:
        return ((temp%mod)**2)%mod
    else:
        return (a*((temp%mod)**2))%mod

def inversemod(a):
    return getpowermod(a,mod-2)

if __name__ == '__main__':
    word = raw_input()
    assert 1 <= len(word) <= 10**5
    assert hasPalindrome(word) == True
    counter = Counter(word)
    denominator = 1
    numerator = 0
    for i in counter:
        numerator += counter[i]/2
        denominator = ((denominator%mod)*(getfactmod(counter[i]/2)%mod))%mod

    numerator = getfactmod(numerator)
    answer = ((numerator%mod)*(inversemod(denominator)%mod))%mod
    print answer
Problem Tester's code :
#include <cstdio>
#include <cstring>
#include <bits/stdc++.h>

using namespace std;
int t;
const long long mod = 1000000007;

long long pow(long long osn){
    long long res = 1, tmp = osn;
    int m = int(mod - 2);
    while(m){
        if(m % 2){
            res = (res * tmp) % mod;
            --m;
        }
        m >>= 1;
        tmp = (tmp * tmp) % mod;
    }
    return res;
}

long long fact(int num){
    long long res(1), curp(num);
    while(curp)res = (res * curp--) % mod;
    return res;
}

int obr(){
    int num[256];
    memset(num, 0, sizeof(num));
    char s[1001];
    cin>>s;
    int n = strlen(s);
    for(int i = 0; i < n; ++i)++num[s[i]];
    for(int i=0 ; i<256 ; i++)
        num[i] = num[i]/2;
    n = n/2;
    long long res = fact(n);
    for(int i = 'a'; i <= 'z'; ++i)
        if(num[i])res = (res * pow(fact(num[i]))) % mod;
    for(int i = 'A'; i <= 'Z'; ++i)
        if(num[i])res = (res * pow(fact(num[i]))) % mod;
    int topr = int(res);
    printf("%d\n", topr);
    return 0;
}

int main(){
    t = 1;
    for(int i = 0; i < t; ++i)
        obr();
    return 0;
}
