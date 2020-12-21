#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll a; cin >> a;
    if (a <= 2) return cout << -1, 0;
    ll c, b;
    if (a % 2 == 0) {
        a /= 2;
        a *= a;
        b = a - 1;
        c = b + 2;
    }
    else {
        a *= a;
        b = (a - 1) / 2;
        c = (a + 1) / 2;
    }
    cout << b << ' ' << c;
}