/**
 * Author: Yanir Edri
 * Date: 2024-11-26
 * License: ??
 * Source: me head
 * Description: Finds all articulation points in an undirected graph.
 * Time: O(|V|+|E|)
 * Status: tested on cses.fi
 */
#pragma once
void articulationPoints(const vvi& g, vi& out) {
    int n = int((g).size());
    vi d(n,-1), cut(n), md(n);
    auto dfs = [&](auto& f, int u = 0, int cd = 0, int p = -1) -> void {
        int chd = 0;
        d[u] = md[u] = cd++;
        for(int v : g[u]) if(v!=p) {
            if(d[v] == -1) {
                f(f,v,cd,u);
                if(md[v]>=d[u]&&p!=-1) cut[u] = 1;
                md[u] = min(md[u],md[v]),++chd;
            } else md[u] = min(md[u],d[v]);
        }
        if(p==-1&&chd>1) cut[u] = 1;
    };
    dfs(dfs);
    fin(u,0,n) if(cut[u]) out.pb(u);
}
