#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long

ll POWER(ll n, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1)res *= n;
        p /= 2;
        n *= n;
    }
    return res;
}

inline void solve() {
    ll x; cin >> x;
    ll sum = 0;
    for (int i = 0; i <= 38;i++) {
        sum += POWER(3, i);
    }
    for (int i = 38; i >= 0; i--) {
        ll p = POWER(3, i);
        if (sum - p >= x) {
            sum -= p;
        }
    }
    cout << sum << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}