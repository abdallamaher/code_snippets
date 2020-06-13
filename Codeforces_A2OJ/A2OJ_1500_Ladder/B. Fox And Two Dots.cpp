#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, ans;
char g[55][55];
bool vis[55][55];

int dr[] = { 0, -1, 0, 1 }, dc[] = { -1, 0, 1, 0 };
bool ok(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m;
}

void dfs(int i, int j, int pr = -1, int pc= -1, int cnt = 0) {
    vis[i][j] = 1;
    for (int Ii = 0; Ii < 4; Ii++) {
        int nr = dr[Ii] + i, nc = j + dc[Ii];
        if (ok(nr, nc) && vis[nr][nc] && g[i][j] == g[nr][nc] && (pr != nr || pc != nc) && cnt >= 3)ans = 1;
        if (ok(nr, nc) && !vis[nr][nc] && g[i][j] == g[nr][nc]) {
            
            dfs(nr, nc, i, j, cnt + 1);
        }
    }
     
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j])
                dfs(i, j);
        }
    }
    if (ans)cout << "Yes";
    else cout << "No";
    return 0;
}