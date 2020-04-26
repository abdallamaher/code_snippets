#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e3 + 7;

int n, m, k, cnt;
int vis[N][N];
queue<pair<int, int>> q;
int r[] = { 0, -1, 0, 1 };
int c[] = { -1, 0, 1, 0 };
bool ok(int r, int c) {
    return r > 0 && r <= n && c > 0 && c <= m;
}

void print() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (!vis[i][j]) {
                printf("%d %d\n", i, j);
            }
        }
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i) {
        if (cnt == n * m - 1) {
            print();
            return 0;
        }
        int a, b; cin >> a >> b;
        vis[a][b] ++;
        cnt++;
        q.push({ a, b });
    }
    while (q.size()) {
        auto v = q.front();
        q.pop();
        if (cnt == n * m - 1) {
            print();
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int nr = v.first + r[i], nc = v.second + c[i];
            if (!vis[nr][nc] && ok(nr, nc)) {
                //printf("%d %d\n", nr, nc);
                q.push({ nr, nc });
                vis[nr][nc]++;
                ++cnt;
            }
        }
    }
    return 0;
}
