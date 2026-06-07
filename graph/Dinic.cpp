#include <bits/stdc++.h>
using namespace std;

#define int long long 

struct edge{
    int to, rev;
    int cap;
    edge(int t=0, int c=0, int r=0):to(t), cap(c), rev(r) {}
};

struct max_flow {
    vector<vector<edge> > G;
    vector<int> level, iter;
    int n;
    max_flow(int n=0):n(n), G(n), level(n), iter(n) {}
    inline int add(int from, int to, int cap) {
        G[from].emplace_back(to, cap, G[to].size());
        G[to].emplace_back(from, 0, G[from].size()-1);
        return G[from].size()-1;
    }
    void bfs(int s) {
        for(int i = 0; i < n; i++) level[i] = -1;
        queue<int> que;
        level[s] = 0;
        que.emplace(s);
        while(!que.empty()) {
        int now = que.front();
        que.pop();
        for(edge &e:G[now]) {
            if(e.cap > 0 and level[e.to] < 0) {
            level[e.to] = level[now] + 1;
            que.emplace(e.to);
            }
        }
        }
    }
    int dfs(int v, int t, int f) {
        if(v == t) return f;
        for(int &i = iter[v]; i < G[v].size(); i++) {
        edge &e = G[v][i];
        if(e.cap > 0 and level[v] < level[e.to]) {
            int d = dfs(e.to, t, min(f, e.cap));
            if(d > 0) {
            e.cap -= d;
            G[e.to][e.rev].cap += d;
            return d;
            }
        }
        }
        return 0;
    }
    int Dinic(int s, int t) {
        int flow = 0;
        while(true) {
        bfs(s);
        if(level[t] < 0) return flow;
        for(int i = 0; i < n; i++) iter[i] = 0;
        int f;
        while((f = dfs(s, t, INT64_MAX)) > 0) flow += f;
        }
    }
};


void solve(){
    int n, m;
    cin >> n >> m;

    max_flow E(2*n+2);
    for(int i=1; i<=n; i++)E.add(0, i, 1), E.add(n+i, 2*n+1, 1);
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        E.add(u, n+v, 1);
        E.add(v, n+u, 1);
    }

    cout << 1013*(2*n-E.Dinic(0,2*n+1));


}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t=1;
    // cin >> t;
    while(t--)solve();
}

/*


*/
