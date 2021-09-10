#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    ll n, k; cin >> n >> k;
    if (k == 1) {
        cout << n << endl;
        return;
    }
    ll ans = 0;
    for (int i = 0; (1ll << i) <= n; i++) {
        ans |= (1ll << i);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}