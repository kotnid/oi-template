#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define vii vector<vector<int>>

const int MOD = 998244353;

vii mul(const vii &a, const vii &b){
    vii c(a.size(), vector<int>(b[0].size(),0));
    for(int i=0; i<a.size(); i++){
        for(int j=0; j<b[0].size(); j++){
            for(int k=0; k<a[0].size(); k++){
                c[i][j] = (c[i][j] + a[i][k]*b[k][j])%MOD;
            }
        }
    }
    return c;
}

vii mfpow(const vii &a, int p){
    if(p==1)return a;
    vii res = mfpow(a, p/2);
    if(p%2==0)return mul(res,res);
    else return mul(a,mul(res,res));
}