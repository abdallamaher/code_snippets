#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long


int n, m, cnt;
int mark[55][55];
int vis[55][55];
int dr[] = { 0, -1, 0, 1 }, dc[] = { -1, 0, 1, 0 };

bool ok(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m && !vis[r][c] && mark[r][c];
}


void dfs(int r, int c) {
    vis[r][c]++;
    for (int ii = 0; ii < 4; ii++) {
        int nr = r + dr[ii], nc = c + dc[ii];
        if(ok(nr,nc))
            dfs(nr, nc);
    }
}

bool check() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((mark[i][j] == 1) && !vis[i][j]) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char x; cin >> x;
            if (x != '.') {
                mark[i][j] = 1;
                cnt++;
            }
        }
    }
   
    // check impossiable
    if (cnt < 3) return cout << -1, 0;

    // check for 1
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int ii = 0; mark[i][j] && ii < 4; ii++) {
                int nr = i + dr[ii], nc = j + dc[ii];
                memset(vis, 0, sizeof(vis));
                if (ok(nr, nc)) {
                    mark[i][j] = 0;
                    dfs(nr, nc);
                    if (check()) {
                        return cout << 1, 0;
                    }
                    mark[i][j] = 1;
                }
            }
        }
    }

    // check for 2
    cout << 2;
    return 0;
}

/*
2 2
aa
aa


3 3
.aa
a.a
aaa
*/