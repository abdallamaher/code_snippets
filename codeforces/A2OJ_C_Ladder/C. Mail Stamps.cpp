#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 7;

int n;
map<int, vector<int>> adj;
map<int, int> d, vis;

void dfs(int i) {
    vis[i]++;
    for (auto it : adj[i]) {
        if (!vis[it])dfs(it);
    }
    cout << i << ' ';
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        d[u]++; d[v]++;
    }
    for (auto it: d) {
        if (it.second == 1) {
            dfs(it.first);
            break;
        }
    }
    return 0;
}
