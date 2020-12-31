#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e4;
vector<int> adj[N];
int vis[N];

int dfs(int i) {
    vis[i] = 1;
    int ret = 0;
    for (auto e : adj[i]) if (!vis[e]) {
        ret += 1 + dfs(e);
    }
    return ret;
}

int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v; scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cnt += dfs(i);
        }
    }
    cout << (1LL << cnt) << endl;
}