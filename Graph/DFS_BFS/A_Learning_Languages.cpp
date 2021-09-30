#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> lang[200], adj[200];
int vis[200];
int n, m, zeros;

void dfs(int i) {
    vis[i] = 1;
    for (auto& it : adj[i])if (!vis[it]) {
        dfs(it);
    }
}

inline void solve() {
    cin >> n >> m;
    for (int i = 1;i <= n; i++) {
        int k; cin >> k;
        if (k == 0) zeros++;
        while (k--) {
            int l; cin >> l;
            lang[l].push_back(i);
        }
    }
    for (auto& it : lang) {
        for (int j = 1; j < it.size(); j++) {
            adj[it[j]].push_back(it[j - 1]);
            adj[it[j - 1]].push_back(it[j]);
        }
    }
    if (zeros == n) {
        cout << n << endl;
        return;
    }
    int cnt = 0;
    for (int i = 1;i <= n; i++)if (!vis[i]) {
        cnt++;
        dfs(i);
    }
    cout << cnt - 1 << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}