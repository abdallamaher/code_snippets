#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
int n;
int ar[3][N];
ll dp[3][N];

ll solve(int p = 0, int i = 0) {
    if (i == n)return 0;
    ll& ret = dp[p][i];
    if (~ret)return ret;

    ret = solve(p, i + 1);
    if(!i || p==0)
        ret = max(ret, solve(1, i + 1) + ar[1][i]);
    if(!i || p==1)
        ret = max(ret, solve(0, i + 1) + ar[0][i]);
    return ret;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ar[0][i];
    }
    for (int i = 0; i < n; i++) {
        cin >> ar[1][i];
    }
    /*memset(dp, -1, sizeof(dp));
    cout << solve();*/
    dp[0][0] = ar[0][0], dp[1][0] = ar[1][0];
    for (int i = 1; i < n; i++) {
        dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + ar[0][i]);
        dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] + ar[1][i]);
    }
    cout << max(dp[0][n - 1], dp[1][n - 1]);
    return 0;
}