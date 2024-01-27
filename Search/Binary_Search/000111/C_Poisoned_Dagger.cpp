#include <bits/stdc++.h>
#ifdef DEBUG
#include "./../Algorithms/competitive_programming/debug.h"
#else
#define debug(...) 42
#endif
using namespace  std;
#define ll long long

inline void solve() {
    ll n, h; cin >> n >> h;
    vector<ll> ar(n);
    for (auto& it : ar)cin >> it;
    ll st = 1, en = h;
    while (st < en) {
        // 0 0 1 1 1
        ll mid = (st + en + 0) / 2;
        ll sum = mid;
        for (int i = 1; i < n; i++) {
            sum += min(mid, ar[i] - ar[i - 1]);
        }
        if (sum >= h)en = mid;
        else st = mid + 1;
    }
    cout << en << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}