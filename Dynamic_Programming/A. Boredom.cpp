#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
int n, mx;
vector<int> v;
int cnt[N];
ll dp[N];
ll solve(int i = 0) {
    if (i >= n)
        return 0;
    if (~dp[i])
        return dp[i];
    ll& a = dp[i];
    a = solve(i + 1);
    if (v[i] == v[i + 1] - 1)
        a = max(a, solve(i + 2) + 1ll * v[i] * cnt[v[i]]);
    else
        a = max(a, solve(i + 1) + 1ll * v[i] * cnt[v[i]]);

    return a;
}
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (!cnt[x])
            v.push_back(x);
        cnt[x]++;
    }
    v.push_back(1e9);
    n = v.size() - 1;
    sort(v.begin(), v.end());
    memset(dp, -1, sizeof(dp));
    cout << solve();
    return 0;
}


/*
table
*/
void table() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[x]++;
        mx = max(x, mx);
    }
    dp[1] = cnt[1];
    for (int i = 2; i <= mx; i++) {
        dp[i] = max(dp[i - 1], 1ll * i * cnt[i] + dp[i - 2]);
    }
    cout << dp[mx] << ' ';
}