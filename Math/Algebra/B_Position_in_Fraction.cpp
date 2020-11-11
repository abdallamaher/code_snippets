#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long

int main() {
    ll a, b, n; cin >> a >> b >> n;
    ll g = __gcd(a, b);
    a /= g;
    b /= g;
    for (int i = 0; i <= 1e6; i++) {
        ll x = a / b;
        if (i && x == n)return cout << i, 0;
        a -= x * b;
        a *= 10;
    }
    cout << -1;
    return 0;
}