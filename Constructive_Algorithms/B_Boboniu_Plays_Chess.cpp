#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int n, m, st, en;
    scanf("%d %d %d %d", &n, &m, &st, &en);
    int vis[105][105] = {};
    printf("%d %d\n%d %d\n", st, en, 1, en);
    vis[st][en] = 1, vis[1][en] = 1;
    for (int i = 1; i <= n;i++) {
        if (i & 1) {
            for (int j = 1; j <= m; j++) {
                if (!vis[i][j])printf("%d %d\n", i, j);
            }
        }
        else {
            for (int j = m; j > 0; j--) {
                if (!vis[i][j])printf("%d %d\n", i, j);
            }
        }
    }
    return 0;
}