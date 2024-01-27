#include <bits/stdc++.h>
#ifdef DEBUG
#include "./../Algorithms/competitive_programming/debug.h"
#else
#define debug(...) 42
#endif
using namespace  std;
#define ll long long

inline void solve() {
    ll y, k, n;
    cin >> y >> k >> n;
    vector<ll> ans;
    for (int q = 1;q <= (int)1e5; q++) {
        ll x = q * k - y;
        if (x>0 && (x + y) <= n) {
            ans.push_back(x);
        }
    }
    debug(ans);
    if (ans.size() == 0) {
        cout << -1 << endl;
        return;
    }
    for (auto& it : ans)cout << it << ' ';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}