#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m;
const int N = 110;
vector<pair<int, int>> adjlist[N];
int vis[N];

void dfs(int i, int c) {
    //printf("%d %d\n", i, c);
    vis[i] = 1;
    for (auto it : adjlist[i]) {
        if (it.second == c && !vis[it.first])
            dfs(it.first, c);
    }
}
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        adjlist[u].push_back({ v, c });
        adjlist[v].push_back({ u, c });
    }
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int st, en;
        cin >> st >> en;
        int ans = 0;
        for (int c = 1; c <= m; c++) {
            memset(vis, 0, sizeof vis);
            dfs(st, c);
            if (vis[en]) ans++;
        }
        cout << ans << endl;
        cerr << "________________" << endl;
    }
    return 0;
}
