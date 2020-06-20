#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
int n, d, k;
ll dp[110][2];

ll solve(int rem=n, int ok=0) {
    if (rem < 0)return 0;
    if (rem == 0) {
        //cout << rem << endl;
        if (ok)return 1;
        else return 0;
    }

    ll& ret = dp[rem][ok];
    if (~ret)return ret;

    ret = 0;
    for (int i = 1; i <= k; i++) {
        ret += solve(rem - i, i>=d?1:ok );

        if (ret > mod)ret %= mod;
    }
    return ret;
}
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k >> d;
    memset(dp, -1, sizeof(dp));
    cout << solve();
    return 0;
}

