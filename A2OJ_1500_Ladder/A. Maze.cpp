#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e2 + 5;
int n, m, k, s;
char g[N][N];
int vis[N][N];
int dr[] = { 0, -1, 0, 1 }, dc[] = { -1, 0, 1, 0 };
bool ok(int r, int c) {
    return r < n && c < m && r >= 0 && c >= 0 && g[r][c] == '.' && !vis[r][c];
}
void dfs(int r, int c) {
    if (!s)return;
    vis[r][c] = 1;

    for (int i = 0; i < 4; i++) {
        int nr = dr[i] + r, nc = dc[i] + c;
        if (ok(nr, nc) && s) {
            s--;
            dfs(nr, nc);
        }
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] == '.')s++;
        }
    }
    s -= k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '.') {
                dfs(i, j);
                i = n;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '.' && !vis[i][j])g[i][j] = 'X';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << g[i][j];
        }cout << '\n';
    }
    return 0;
}
