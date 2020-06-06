#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
int n, W, ans;
ll dp[N][110];
int w[110], v[110];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> W;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    for (int c = 1; c <= n; c++) {
        for (int r = 0; r < N; r++) {
            dp[r][c] = 1e15;
        }
    }
    dp[0][1] = 0, dp[v[1]][1] = w[1];
    for (int c = 1; c <= n; c++) {
        for (int r = 0; r < N; r++) {
            if (dp[r][c] > W)continue;

            dp[r][c + 1] = min(dp[r][c + 1], dp[r][c]);

            if(r + v[c+1] < N)
                dp[r + v[c + 1]][c + 1] = min(dp[r + v[c + 1]][c + 1], dp[r][c] + w[c+1]);
        }
    }
    for (int i = 0; i < N; i++) {
        if (dp[i][n] <= W) {
            ans = i;
        }
    }
    cout << ans;
    return 0;
}