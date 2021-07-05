#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll __gcd(ll a, ll b) {
    return b ? __gcd(b, a % b) : a;
}

inline void solve() {
    ll a, b, base; 
    scanf("%lld%lld%lld", &a, &b, &base);

    b /= __gcd(a, b);           // make a, b coprimes    a * 1/b
    ll g = __gcd(b, base);      // see if b can reach 1 in this base
    while (g > 1) {
        while (b % g == 0) b /= g;

        g = __gcd(b, base);
    }

    if (b == 1)puts("Finite");
    else puts("Infinite");
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}