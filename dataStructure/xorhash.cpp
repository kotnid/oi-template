#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
const int bas1=17680321,bas2=19260817;
const int N = 1e5+5;

struct HASH: pair<ull,ull>{
    void operator^=(const HASH &x){
        first ^= x.first;
        second ^= x.second; 
    }   
}hs[N];

HASH init(int n){
    hs[0].first = hs[0].second = 1;
    HASH full;
    for(int i=1; i<=n; i++){
        hs[i].first = hs[i-1].first * bas1;
        hs[i].second = hs[i-1].second * bas2;
        full ^= hs[i];
    }
    return full;
}

/*
support add/ rm element (without order)
complement (full^subset = complement)
*/



