#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll POWER(ll n, ll  p) {
    ll res = 1;
    while (p) {
        if (p & 1)res *= n;
        p /= 2;
        n *= n;
    }
    return res;
}

inline void solve() {
    ll n; cin >> n;
    // prime_divisors
    map<ll, ll> mp;
    ll N = n;
    for (ll i = 2; i * i <= N; i++) {
        while (N % i == 0) {
            mp[i]++;
            N /= i;
        }
    }
    if (N > 1)mp[N]++;
    ll num = 0, len = 0;
    for (auto& [key, val] : mp) {
        if (val > len) {
            num = key;
            len = val;
        }
    }
    // small os them
    cout << len << endl;
    for (int i = 0; i < len - 1; i++) {
        cout << num << ' ';
    }
    cout << n / POWER(num, len - 1) << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}