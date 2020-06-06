#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 5;
const int N = 1e7 + 5;

int n, m, t, d;
int dp[110][12345];

int solve(int tt=2, int res = n) {
    if (tt > t) {
        if (res == m)return n;
        return -1e9;
    }
    if (~dp[tt][res]) 
        return dp[tt][res];

    int ans = -1e9; // can't be 0, must be -1e9 not to block the invalid case
    for (int i = 0; i <= d; ++i) {
        int a = solve(tt + 1, res + i) + res + i;
        int b = solve(tt + 1, res - i) + res - i;
        ans = max(ans, max(a, b));
    }
    return dp[tt][res] = ans;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> t >> d;
    memset(dp, -1, sizeof(dp));
    cout << solve() << "\n";
    return 0;
}



void table(){
    int dp[12345][110];
    dp[n][1] = n;
    for (int i = 1; i <= t; i++) {
        for (int j = 1; j <= 2000; j++) {
            int v = dp[j][i];
            if (!v) continue;
            for (int x = 0; x <= d; x++) {
                if (j - x > 0) dp[j - x][i + 1] = max(dp[j - x][i + 1], v + j-x);
                dp[j + x][i + 1] = max(dp[j + x][i + 1], v + j+x);
            }
        }
    }
    cout << dp[m][t];
    return 0;
}