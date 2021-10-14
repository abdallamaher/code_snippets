#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, k, u, v;
const int N = 2e5 + 5;
int vis[N];
int ar[N];
vector<int> adj[N];

int dfs(int i, int p, int cnt) {
    if (cnt > k)return 0;
    int ret = 0, ok = 0;
    for (auto e : adj[i])if (e != p) {
        ret += dfs(e, i, ar[e] ? cnt + 1 : 0);
        ok = 1;
    }
    if (ok == 0) return 1;
    else        return ret;
}

inline void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)cin >> ar[i];
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << dfs(1, 0, ar[1]) << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}