#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, x, y;
const int N = 1e3 + 5;
int ar[3][N];
int dp[3][N];
int mem[N][N][2];

int table() {
    scanf("%d %d %d %d", &n, &m, &x, &y);
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            char c; cin >> c;
            if (c == '#')ar[0][j]++;
            else ar[1][j]++;
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = 1e9;
        }
    }

    for (int i = m; i > 0; i--) {
        int sum0 = 0, sum1 = 0;
        for (int j = i; j > 0; j--) {
            sum0 += ar[0][j], sum1 += ar[1][j];
            if (i - j + 1 >= x && i - j + 1 <= y) {
                dp[0][j] = min(dp[0][j], sum0 + dp[1][i + 1]);
                dp[1][j] = min(dp[1][j], sum1 + dp[0][i + 1]);
            }
        }
    }

    cout << min(dp[0][1], dp[1][1]);
    return 0;
}



int solve(int i = 0, int len = 0, int col = 0) {
    if (i == m) {
        if (len >= x && len <= y)return 0;
        return 1e9;
    }
    int& ret = mem[i][len][col];
    if (~ret)return ret;
    ret = 1e9;
    if (!len || len < y)
        ret = min(ret, solve(i + 1, len + 1, col) + n - ar[col ^ 1][i]);
    if (!len || len >= x)
        ret = min(ret, solve(i + 1, 1, col ^ 1) + n - ar[col][i]);
    return ret;
}
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> x >> y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            if (c == '#')ar[0][j]++;
            else ar[1][j]++;
        }
    }

    memset(mem, -1, sizeof(mem));
    cout << solve();
    return 0;
}

