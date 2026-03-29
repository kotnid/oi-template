vector<int> hierholzer(int st){ // find euler cycle
    vector<int>res;
    stack<int>sk;
    sk.push(st);

    while(sk.size()){
        int u = sk.top();
        if(g[u].size()){
            auto [v,w] = g[u].back();
            g[u].pop_back();
            if(vis[w])continue;
            vis[w] = 1;
            used[w] = (u!=a[w]);
            sk.push(v);
        }else{
            res.push_back(u);
            sk.pop();
        }
    }
    return res;
}