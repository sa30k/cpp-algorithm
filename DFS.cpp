#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &G, int v, vector<int> &seen) {
    seen[v] = true;

    for (auto next_v: G[v]) { 
        if (seen[next_v]) continue;
        dfs(G, next_v);
    }
}