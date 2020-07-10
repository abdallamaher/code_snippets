#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, ans, cnt;
const int N = 105;
vector<int> adjlist[N];
int lev[N];
int vis[N];

int dfs(int i) {
    vis[i] = 1;
    int deep = 0;
    for (auto it : adjlist[i]) {
        if (vis[it])continue;
        deep = max(deep, dfs(it) + 1);
    }
    return deep;
}

inline void init() {
    memset(lev, 0, sizeof lev);
    for (auto& it : adjlist) {
        it.clear();
    }
    cnt = 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    while (n--) {
        init();
        cin >> m;
        while (--m) {
            int u, v; cin >> u >> v;
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
        for (int i = 1; i <= 100; i++) {
            lev[i] = dfs(i);
            memset(vis, 0, sizeof(vis));
        }
        for (int i = 1; i <= 100; i++) {
            cnt = max(cnt, lev[i]);
        }
        ans += cnt;
    }
    cout << ans;
    return 0;
}