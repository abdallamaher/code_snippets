#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m;
char g[55][55];
bool vis[55][55];

void move1(int r, int c) {
    vis[r][c] = 1;
    for (int i = r; i < n && g[i][c] == 'B'; i++) {
        for (int j = c; j < m && g[i][j] == 'B'; j++) {
            vis[i][j] = 1;
        }
        for (int j = c; j >=0 && g[i][j] == 'B'; j--) {
            vis[i][j] = 1;
        }
    }
    for (int i = r; i >= 0 && g[i][c] == 'B'; i--) {
        for (int j = c; j < m && g[i][j] == 'B'; j++) {
            vis[i][j] = 1;
        }
        for (int j = c; j >= 0 && g[i][j] == 'B'; j--) {
            vis[i][j] = 1;
        }
    }
}
void move2(int r, int c) {
    vis[r][c] = 1;
    for (int i = c; i < m && g[r][i] == 'B'; i++) {
        for (int j = r; j < n && g[j][i] == 'B'; j++) {
            vis[j][i] = 1;
        }
        for (int j = r; j >= 0 && g[j][i] == 'B'; j--) {
            vis[j][i] = 1;
        }
    }
    for (int i = c; i >=0 && g[r][i] == 'B'; i--) {
        for (int j = r; j < n && g[j][i] == 'B'; j++) {
            vis[j][i] = 1;
        }
        for (int j = r; j >= 0 && g[j][i] == 'B'; j--) {
            vis[j][i] = 1;
        }
    }
}

void check() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'B' && !vis[i][j]) {
                cout << "NO";
                exit(0);
            }
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
            if (g[i][j] == 'B') {
                memset(vis, 0, sizeof(vis));
                move1(i, j);
                move2(i, j);
                check();
            }
        }
    }
    cout << "YES";
    return 0;
}

