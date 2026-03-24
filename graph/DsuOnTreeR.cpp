const int N = 5e5+5;
const int M = 1<<22;
const int INF = 1e9;

typedef array<int,2>ar;

vector<ar>g[N];
int sz[N], son[N], dfn[N], fa[N], btm[N], totdfn;
int top[N], rnk[N];
int ans[N], mx[M], val[N], dep[N];

void init(int u){
    mx[val[u]] = -INF;
    for(auto [v,w] : g[u])init(v);
}

void ins(int u){
    mx[val[u]] = max(mx[val[u]], dep[u]);
    for(auto [v,w] : g[u])ins(v);
}

void getAns(int u, int o){
    ans[o] = max(ans[o], dep[u]+mx[val[u]]);
    for(int i=0; i<22; i++)ans[o] = max(ans[o], dep[u]+mx[val[u]^(1<<i)]);
    for(auto [v,w] : g[u])getAns(v,o);
}

void dfs0(int u, int p){
    sz[u] = 1;
    fa[u] = p;
    dep[u] = dep[p]+1;
    for(auto [v,w] : g[u]){
        if(v == p)continue;
        val[v] = val[u]^w;
        dfs0(v, u);
        sz[u] += sz[v];
        if(!son[u] || sz[son[u]] < sz[v])son[u] = v;
    }
}

void dfs1(int u){
    for(auto [v,w] : g[u])if(v != son[u])dfs1(v), init(v);
    if(son[u])dfs1(son[u]);
    for(auto [v,w] : g[u])if(v != son[u])getAns(v,u), ins(v);
    mx[val[u]] = max(mx[val[u]], dep[u]);
    ans[u] = max(ans[u], dep[u]+mx[val[u]]);
    for(int i=0; i<22; i++)ans[u] = max(ans[u], dep[u]+mx[val[u]^(1<<i)]);
    ans[u] -= dep[u]*2;
    for(auto [v,w] : g[u])ans[u] = max(ans[u], ans[v]);
}

void solve(){
    int n;
    cin >> n;
    
    for(int i=0; i<M; i++)mx[i] = -INF;

    for(int i=2; i<=n; i++){
        int u;
        char c;
        cin >> u >> c;
        g[u].push_back({i,1<<(c-'a')});
    }
    dfs0(1,1);
    dfs1(1);
    for(int i=1; i<=n; i++)cout << ans[i] << " ";
}