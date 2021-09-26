#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m;
const int N = 2e5 + 5;
vector<int> adjList[N];
int vis[N];

bool dfs(int u) {
    int ret = true;
    if (adjList[u].size() != 2)return false;
    vis[u] = 1;
    for (auto& e : adjList[u]) if (!vis[e])
        ret &= dfs(e);
    return ret;
}

inline void solve() {
    int n, m; cin >> n >> m;
    for (int i = 0;i < m; i++) {
        int u, v; cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            ans += dfs(i);
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}