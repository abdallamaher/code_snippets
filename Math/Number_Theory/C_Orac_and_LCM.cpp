#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll LCM(ll a, ll b) {
    return a / __gcd(a, b) * b;
}

int main() {
    ll n; cin >> n;
    vector<ll> v(n), sufix(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &v[i]);
    }
    ll g = 0;
    for (int i = n - 1; i >= 0; i--) {
        g = __gcd(g, v[i]);
        sufix[i] = g;
    }

    ll ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans = __gcd(ans, LCM(v[i], sufix[i + 1]) );
    }
    cout << ans << endl;
}