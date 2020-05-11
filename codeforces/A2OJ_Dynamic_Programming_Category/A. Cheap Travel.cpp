#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, a, b;
int dp[1005];

int solve(int rem) {
    if (rem <= 0)return 0;
    if (~dp[rem])
        return dp[rem];
    int ans = 1e8;
    ans = min(ans, a + solve(rem - 1));
    ans = min(ans, b + solve(rem - m));
    return dp[rem] = ans;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> a >> b;
    memset(dp, -1, sizeof(dp));
    cout << solve(n);
    return 0;
}
