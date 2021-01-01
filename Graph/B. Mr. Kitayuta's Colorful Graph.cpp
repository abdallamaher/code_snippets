#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<int, int>> adj[105];
int vis[105];

int dfs(int a, int b, int c) {
    if (a == b)return 1;
    vis[a] = 1;
    int ret = 0;
    for (auto e : adj[a]) if (!vis[e.first] && c == e.second) {
        ret |= dfs(e.first, b, e.second);
    }
    vis[a] = 0;
    return ret;
}

int main() {
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        adj[a].push_back({ b, c });
        adj[b].push_back({ a, c });
    }
    int q;cin >> q;
    while (q--) {
        int a, b; scanf("%d %d", &a, &b);
        int ans = 0;
        for (int c = 1;c <= m; c++) {
            ans += dfs(a, b, c);
        }
        printf("%d\n", ans);
    }
}