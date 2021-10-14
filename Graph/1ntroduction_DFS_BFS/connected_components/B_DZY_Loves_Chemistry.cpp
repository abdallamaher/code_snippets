#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m;
int adj[100][100];
int vis[100];

int dfs(int i) {
    vis[i] = 1;
    int ret = 0;
    for (int j = 1; j <= n; j++) if (adj[i][j] && !vis[j]) {
        ret += 1 + dfs(j);
    }
    return ret;
}

inline void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u][v] = adj[v][u] = 1;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cnt += dfs(i);
        }
    }
    cout << (1ull << cnt) << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}