#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll lcm(ll a, ll b) {
    return a / __gcd(a, b) * b;
}

int main() {
    ll n; cin >> n;
    ll ans = 0;
    for (ll i = n; i >= n - 100 && i > 0; i--) {
        for (ll j = n; j >= n - 100 && j > 0; j--)
            for (ll k = n; k >= n - 100 && k > 0; k--) {
                ans = max(ans, lcm(i, lcm(j, k)));
            }
    }
    cout << ans;
}