#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 5e3 + 10;
int n, m, k;
ll ar[N];
ll dp[N][N];

ll solve(int i, int rem) {
    if (i > n || rem == 0)return 0;
    ll& ret = dp[i][rem];
    if (~ret)return ret;
    ll leave = solve(i + 1, rem);
    ll take = -1e14;
    if (i + m - 1 <= n)
        take = solve(i + m, rem - 1) + ar[i + m - 1] - ar[i - 1];
    return ret = max(leave, take);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        ar[i] += ar[i - 1];
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(1, k) << endl;
}