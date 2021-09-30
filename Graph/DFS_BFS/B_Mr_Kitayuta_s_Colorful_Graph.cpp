#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m;
vector<pair<int, int>> adj[200];
int vis[200];
int st, en;

int dfs(int st, int en, int c) {
    if (st == en)return 1;
    vis[st] = 1;
    int ret = 0;
    for (auto& it : adj[st])
        if (!vis[it.first] && c == it.second) {
            ret |= dfs(it.first, en, c);
        }
    vis[st] = 0;
    return ret;
}

inline void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, c; cin >> u >> v >> c;
        adj[u].push_back({ v, c });
        adj[v].push_back({ u, c });
    }
    int q; cin >> q;
    while (q--) {
        cin >> st >> en;
        int ans = 0;
        for (int c = 1;c <= m; c++) {
            // memset(vis, 0, sizeof(vis));
            ans += dfs(st, en, c);
        }
        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}