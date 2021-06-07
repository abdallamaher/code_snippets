#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    ll a, b, q; cin >> a >> b >> q;
    if (a > b)swap(a, b);
    // [1 : b - 1] and lcm   is    equal
    // [b : lcm - 1]     not   equal
    ll lcm = (a * b) / __gcd(a, b);
    ll not_equal = lcm - b;
    while (q--) {
        ll l, r; cin >> l >> r;

        ll f1 = (l - 1) / lcm * not_equal;
        ll f = (l - 1) % lcm;
        f1 += max(0ll, f - b + 1);

        ll f2 = r / lcm * not_equal;
        f = r % lcm;
        f2 += max(0ll, f - b + 1);


        printf("%lld ", f2 - f1);
    }
    puts("");
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}