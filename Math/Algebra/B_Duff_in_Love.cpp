#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool go(ll x) {
    return sqrt(x * 1.0) == (int)sqrt(x * 1.0);
}

bool can(ll n) {
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i > 1 && go(i))return 0;
            if (n/i > 1 && go(n / i))return 0;
        }
    }
    return 1;
}

int main() {
    ll n;cin >> n;
    ll mx = 0;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (can(i))mx = max(i, mx);
            if (can(n / i))mx = max(n / i, mx);
        }
    }
    cout << mx << endl;
    return 0;
}