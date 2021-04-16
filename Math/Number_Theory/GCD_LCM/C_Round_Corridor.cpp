#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll g, n, m, q;

ll get(ll a, ll x) {
    if (a == 1) {
        return(x - 1) / (n / g);
    }
    else {
        return (x - 1) / (m / g);
    }
}

int main() {
    cin >> n >> m >> q;
    g = __gcd(n, m);
    while (q--) {
        ld a, b, f, s;
        cin >> a >> f >> b >> s;
        puts(get(a, f) == get(b, s) ? "YES" : "NO");
    }
}