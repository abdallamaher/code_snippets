#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 2e5 + 5;
int n, m;
vector<int> adj[N];
int dp[N];

int dfs(int i) {
    int& ret = dp[i];
    if (~ret)return ret;
    ret = 0;
    for (auto& e : adj[i]) {
        ret = max(ret, dfs(e) + 1);
    }
    return ret;
}

inline void solve() {
    cin >> n >> m;
    for (int i = 0; i < m;i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    int ans = 0;
    memset(dp, -1, sizeof(dp));
    for (int i = 1;i <= n; i++) {
        if (dp[i] == -1) {
            ans = max(ans, dfs(i));
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