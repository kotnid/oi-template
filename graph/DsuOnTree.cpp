const int N = 2e5+5;

vector<int>g[N];
int sz[N], son[N], col[N], dfn[N], fa[N], btm[N], totdfn;
int top[N], rnk[N];
int ans[N], cnt[N], totColor;

void add(int u){
    if(!cnt[col[u]])++totColor;
    cnt[col[u]]++;
}

void del(int u){
    cnt[col[u]]--;
    if(!cnt[col[u]])--totColor;
}

int getAns(){
    return totColor;
}

void dfs0(int u, int p){
    sz[u] = 1;
    fa[u] = p;
    for(int v : g[u]){
        if(v == p)continue;
        dfs0(v, u);
        sz[u] += sz[v];
        if(!son[u] || sz[son[u]] < sz[v])son[u] = v;
    }
}

void dfs1(int u, int t){
    rnk[btm[u] = dfn[u] = ++totdfn] = u;
    top[u] = t;
    if(!son[u])return ;
    dfs1(son[u], t);
    for(int v : g[u]){
        if(v == fa[u] || v == son[u])continue;
        dfs1(v, v);
    }
    btm[u] = totdfn;
}

void dsu_on_tree(){
    for(int i=totdfn; i>=1; i--){
        int u = rnk[i];
        for(int v : g[u]){
            if(v == fa[u] || v == son[u])continue;
            for(int i=dfn[v]; i<=btm[v]; i++)add(rnk[i]);
        }
        add(u);
        ans[u] = getAns();
        if(u == top[u]){
            for(int i=dfn[u]; i<=btm[u]; i++)del(rnk[i]);
        }
    }
}


void solve(){
    int n;
    cin >> n;
    for(int i=1; i<n; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1; i<=n; i++)cin >> col[i];

    dfs0(1,1);
    dfs1(1,1);
    dsu_on_tree();

    int m;
    cin >> m;
    for(int i=1; i<=m; i++){
        int q;
        cin >> q;
        cout << ans[q] << "\n";
    }
}