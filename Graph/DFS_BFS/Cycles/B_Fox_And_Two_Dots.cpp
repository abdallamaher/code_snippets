#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m, cycle;
char g[55][55];
int vis[55][55];
int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

bool ok(int r, int c) {
    return r < n&& c < m&& r >= 0 && c >= 0;
}

void dfs(int r, int c, pair<int, int> p) {
    vis[r][c] = 1;
    for (int i = 0; i < 4;i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (ok(nr, nc) && g[r][c] == g[nr][nc]) {
            if (vis[nr][nc] && p != make_pair(nr, nc))cycle = 1;
            if (!vis[nr][nc])dfs(nr, nc, { r, c });
        }
    }
}

inline void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }
    for (int i = 0;i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j]) {
                dfs(i, j, { 0, 0 });
            }
        }
    }
    cout << (cycle ? "Yes\n" : "No\n");
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}