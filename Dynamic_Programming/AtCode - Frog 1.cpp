#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
int n;
int heights[N];
int dp[N];
int solve(int i = 0) {
    if (i == n - 1) return 0;
    if (~dp[i])return dp[i];
    int ans = abs(heights[i + 1] - heights[i]) + solve(i + 1);
    if (i < n - 2) {
        ans = min(ans, abs(heights[i + 2] - heights[i]) + solve(i + 2));
    }
    return dp[i] = ans;
}
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << solve();
    return 0;
}
