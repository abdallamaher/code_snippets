#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3 + 5;
int n, m, x, y;
char g[N][N];
int ar[3][N];
int dp[N][N][2];
int solve(int i = 0, int len = 0, int col=0) {
    if (i == m) {
        if (len >= x && len <= y)return 0;
        return 1e9;
    }
    int& ret = dp[i][len][col];
    if (~ret)return ret;
    ret = 1e9;
    if(!len || len < y)
        ret = min(ret, solve(i + 1, len + 1, col) + n - ar[col ^ 1][i]);
    if(!len || len >= x)
        ret = min(ret, solve(i + 1, 1, col ^ 1) + n - ar[col][i]);
    return ret;
}
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> x >> y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (g[j][i] == '#')ar[0][i]++;
            else ar[1][i]++;
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << solve();
    return 0;
}


