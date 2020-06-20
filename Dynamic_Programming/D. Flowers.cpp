#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7, N = 1e5 + 5;
int n, k;
ll dp[N];
ll solve(int rem = N-2) {
    //cout << rem << endl;
    if (rem == 0)return 1;
    if (rem < 0)return 0;
    ll& ret = dp[rem];
    if (~ret)return ret;

    return ret = (solve(rem - 1) + solve(rem - k))%mod;
}
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    memset(dp, -1, sizeof(dp));
    solve();
    for (int i = 1; i < N; ++i) {
        //cout << dp[i] << ' ';
        dp[i] += dp[i - 1];
        if(dp[i] > mod)dp[i]%=mod;
    }
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        cout << (dp[r] - dp[l - 1] + mod)%mod << endl;
    }
    return 0;
}

