#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n, g, b; scanf("%d%d%d", &n, &g, &b);
    ll half_g = (n + 1) / 2;
    ll need_g = half_g / g;
    
    ll ans = need_g * (g + b);
    if (half_g % g)ans += half_g % g;
    else ans -= b;
    cout << max(1ll * n, ans) << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}