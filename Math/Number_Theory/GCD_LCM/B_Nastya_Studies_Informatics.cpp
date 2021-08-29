#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll l, r, x, y;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main() {
    cin >> l >> r >> x >> y;
    ll mul = x * y;
    ll cnt = 0;
    /*
    gcd(a, b) = x
    so a should be x 2x 3x 4x
       a in form  k*gcd

    a*b = x*y
    */
    for (ll i = x; i * i <= mul; i += x) {
        if (mul % i == 0 &&
            l <= i &&
            mul / i <= r &&
            gcd(i, mul / i) == x &&
            lcm(i, mul / i) == y) {

            cnt += 1 + (i != mul / i);
        }
    }
    cout << cnt << endl;
}