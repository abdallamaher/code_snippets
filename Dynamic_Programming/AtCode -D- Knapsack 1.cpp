#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
int n, w;
ll dp[105][N];
pair<int, int> ar[105];

ll solve(int i, int rem) {
    if (i > n)return 0;
    if (~dp[i][rem])
        return dp[i][rem];
    ll ans = solve(i + 1, rem);
    if (rem >= ar[i].first) {
        ans = max(ans, solve(i + 1, rem - ar[i].first) + ar[i].second);
    }
    return dp[i][rem] = ans;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        int s, v; cin >> s >> v;
        ar[i] = { s, v };
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(1, w);
    return 0;
}