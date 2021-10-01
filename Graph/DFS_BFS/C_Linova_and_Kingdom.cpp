#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, k;
const int N = 2e5 + 5;
vector<int> adj[N];
int vis[N], dis[N];
vector<int> v;

int dfs(int i, int lev = 1) {
    dis[i] = lev;
    int ret = 1;
    for (auto it : adj[i]) if (!dis[it]) {
        ret += dfs(it, lev + 1);
    }
    v.push_back(dis[i] - ret);
    return ret;
}

inline void solve() {
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    sort(v.rbegin(), v.rend());

    ll ans = 0;
    for (int i = 0; i < k; i++) {
        ans += v[i];
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}