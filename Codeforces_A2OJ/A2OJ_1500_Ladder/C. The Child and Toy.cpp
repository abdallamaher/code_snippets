#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3 + 4;
int n, m;
int ar[N];
int vis[N];
vector<pair<int, int>> adj[N];

int dfs(int i) {
    int sum = 0;
    vis[i]++;
    for (auto it : adj[i]) {
        if (!vis[it.first]) {
            sum += it.second;
        }
    }
    return sum;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back({ v, min(ar[u], ar[v]) });
        adj[v].push_back({ u, min(ar[u],ar[v]) });
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            sum += dfs(i);
        }
    }
    cout << sum;
}