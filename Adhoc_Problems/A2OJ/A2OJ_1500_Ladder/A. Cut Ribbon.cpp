#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 4e3 + 5;
int n, a, b, c;
int dp[N];

int solve(int rem) {
    if (rem < 0) return -1e7;
    if (rem == 0) return 0;

    int& ret = dp[rem];
    if (~ret) return ret;
    ret = solve(rem - a) + 1;
    ret = max(solve(rem - b) + 1, ret);
    ret = max(solve(rem - c) + 1, ret);
    return ret;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> a >> b >> c;
    memset(dp, -1, sizeof(dp));
    cout << solve(n);
    return 0;
}
