#include <bits/stdc++.h>
using namespace std;
#define ll long long

int dr[] = { -1, 0, 1, 0 }, dc[] = { 0, 1, 0, -1 };
int n, m, k;
char g[505][505];
int vis[505][505];

bool ok(int r, int c) {
    return r < n&& c < m&& r >= 0 && c >= 0 && !vis[r][c] && g[r][c] == '.';
}

void dfs(int r, int c) {
    vis[r][c] = 1;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if (ok(nr, nc)) {
            dfs(nr, nc);

        }
    }
    if (k > 0) {
        g[r][c] = 'X';
        k--;
    }
}

inline void solve() {
    cin >> n >> m >> k;
    int r = -1, c = -1;
    for (int i = 0;i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (r == -1 && g[i][j] == '.') {
                r = i;
                c = j;
            }
        }
    }
    dfs(r, c);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << g[i][j];
        }
        cout << endl;
    }

}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}