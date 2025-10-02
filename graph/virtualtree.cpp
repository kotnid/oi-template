#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int> pii;
const int N = 5e5+5;
int dep[N], sz[N], pa[N], son[N], top[N], stk[N], dfn[N], clk, tp, mn[N];
vector<pii> G[N];
vector<int> E[N];
void dfs1(int u, int fa, int d) {
	dfn[u] = ++clk;
	dep[u] = d;
	sz[u] = 1;
	son[u] = 0;
	pa[u] = fa;
	for (auto [v,w] : G[u]) if (v != fa) {
        mn[v] = min(mn[u],w);
		dfs1(v, u, d + 1);
		sz[u] += sz[v];
		if (sz[son[u]] < sz[v])
			son[u] = v;
	}
}
void dfs2(int u, int tp) {
	top[u] = tp;
	if (son[u])
		dfs2(son[u], tp);
	for (auto [v,w] : G[u]) if (v != pa[u] && v != son[u])
		dfs2(v, v);
}
int lca(int x, int y) {
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]])
			swap(x, y);
		x = pa[top[x]];
	}
	return dep[x] < dep[y] ? x : y;
}
int dist(int x, int y) {
	return dep[x] + dep[y] - 2 * dep[lca(x, y)];
}
void init(int root) {
	clk = 0; stk[0] = -1;
    mn[root] = 1e14;
	dfs1(root, 0, 1);
	dfs2(root, root);
}
void ins(int x) {
	if (tp > 0) {
		int fa = lca(stk[tp], x);
		if (fa != stk[tp]) {
			while (tp > 1 && dep[fa] < dep[stk[tp - 1]]) {
				E[stk[tp - 1]].push_back(stk[tp]);
				--tp;
			}
			int last = stk[tp--];
			if (fa != stk[tp]) {
				E[fa].clear();
				stk[++tp] = fa;
			}
			E[fa].push_back(last);
		}
	}
	E[x].clear();
	stk[++tp] = x;
}
int build(vector<int> nodes) {
	sort(nodes.begin(), nodes.end(), [](int x, int y) {
		return dfn[x] < dfn[y];
	});
	for (auto i : nodes)
		ins(i);
	while (--tp) 
		E[stk[tp]].push_back(stk[tp + 1]);
	return stk[1];
}

vector<bool>need(N,0);
int dfs(int u, int p){
    int res = 0;
    for(int v : E[u]){
        if(v==p)continue;
        res += min(mn[v],dfs(v,u));
    }
    if(need[u]){
        return res + mn[u];
    }else{
        return min(res, mn[u]);
    }
}

int32_t main() {
	int n;
    cin >> n;

    for(int i=1; i<n; i++){
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    init(1);

    int q;
    cin >> q;
    while(q--){
        int k;
        cin >> k;
        vector<int>a(k);
        for(auto &e : a)cin >> e;
        for(auto e : a)need[e] = 1;
        a.push_back(1);
        int rt = build(a);
        cout << dfs(rt,0) << "\n";
        for(auto e : a)need[e] = 0;
    }
}