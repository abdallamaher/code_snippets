#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    vector<int> cnt(32);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[32 - __builtin_clz(x)]++;
    }

    ll ans = 0;
    for (auto& val : cnt) {
        ans += 1ll * val * (val - 1) / 2;
    }

    cout << ans << endl;
}

inline void go() {
    int n; cin >> n;
    vector<int> ar(n);
    for (auto& it : ar)cin >> it;

    ll ans = 0;
    for (int bit = 0; bit < 32; ++bit) {
        ll cnt = 0;
        for (auto& it : ar) {
            if (it >= (1 << bit) && it < (1 << (bit + 1)))  // check last 1 bit
                cnt++;
        }
        ans += cnt * (cnt - 1) / 2;
    }

    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}