#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n, k; cin >> n >> k;
    int degree[n] = {}, depth[n] = {};
    vector<int> adj[n] = {};
    queue<int> q;

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[v].push_back(u);
        adj[u].push_back(v);
        degree[u]++, degree[v]++;
    }
    int f = 0;
    for (int i = 0; i < n; i++)if (degree[i] <= 1)q.push(i);
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (auto& it : adj[u]) {
            if (degree[it] <= 1)continue;   // prevent cycle if two leave nodes
            degree[it]--;
            depth[it] = max(depth[it], depth[u] + 1);
            if (degree[it] == 1)q.push(it);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)if (depth[i] >= k)ans++;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}