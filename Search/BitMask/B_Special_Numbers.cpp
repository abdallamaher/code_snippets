#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mod = 1e9 + 7;

ll POWER(ll n, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1)res = (res * n) % mod;
        n = (n * n) % mod;
        p /= 2;
    }
    return res;
}

inline void solve() {
    ll n, k; cin >> n >> k;
    ll sum = 0;
    for (int i = 0; i < 32; i++) {
        if (k & (1 << i)) {
            sum += POWER(n, i);
            if (sum > mod)sum %= mod;
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