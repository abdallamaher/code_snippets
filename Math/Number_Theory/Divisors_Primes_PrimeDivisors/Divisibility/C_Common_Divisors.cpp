#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

inline void solve() {
    int n;  cin >> n;
    ll g = 0;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        g = gcd(g, x);
    }
    // divisors
    ll ans = 0;
    for (ll j = 1; j * j <= g; j++) {
        if (g % j)continue;
        ans++;
        if (j != g / j)ans++;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}