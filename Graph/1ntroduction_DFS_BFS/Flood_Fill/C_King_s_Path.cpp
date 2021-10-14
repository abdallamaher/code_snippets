#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5 + 5;
int  sx, sy, ex, ey;
int dr[] = { -1, -1, -1, 0, 1, 1, 1, 0 },
dc[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
map<pair<int, int>, int> adj, dis;

void dfs(int r, int c) {
    queue<pair<int, int>> q;
    q.push({ r, c });
    dis[{r, c}] = 0;
    while (q.size()) {
        auto u = q.front();
        q.pop();
        for (int i = 0; i < 8;i++) {
            int nr = u.first + dr[i];
            int nc = u.second + dc[i];
            if (adj[{nr, nc}] && !dis[{nr, nc}]) {
                q.push({ nr, nc });
                dis[{nr, nc}] = 1 + dis[{u.first, u.second}];
            }
        }
    }
}

inline void solve() {
    cin >> sx >> sy >> ex >> ey;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int r, a, b; cin >> r >> a >> b;
        for (int j = a; j <= b;j++)adj[{r, j}] = 1;
    }
    dfs(sx, sy);
    if (dis[{ex, ey}])cout << dis[{ex, ey}];
    else cout << -1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;    
    while (t--)solve();
}