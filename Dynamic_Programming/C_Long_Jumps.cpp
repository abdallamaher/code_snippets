#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    ll ar[n + n] = {};
    ll dp[n + n] = {};
    for (int i = 0; i < n; i++) {
        scanf("%d", ar + i);
        dp[i] = ar[i];
    }
    for (int i = 0; i < n; i++) {
        if (i + ar[i] < n) {
            ll& ret = dp[i + ar[i]];
            ret = max(ret, dp[i] + ar[i + ar[i]]);
        }
    }
    ll mx = 0;
    for (int i = 0; i < n;i++)mx = max(mx, dp[i]);
    cout << mx << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}