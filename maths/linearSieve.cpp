#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int> pii;

const int MOD = 998244353;

const int N = 1e7+1;
vector<int>lpf(N+1,0);

vector<pii>fact(int x){
    vector<pii>res;
    while(x > 1){
        int p = lpf[x], cn = 0;
        while(x%p==0)x /= p, cn++;
        res.push_back({p,cn});
    }
    return res;
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int>pri;
    iota(lpf.begin(), lpf.end(), 0);
    for(int x=2; x<N; x++){
        if(lpf[x] == x)pri.push_back(x);
        for(auto p : pri){
            if(p*x > N || p > lpf[x])break;
            lpf[p*x] = p;
        }
    }
}

