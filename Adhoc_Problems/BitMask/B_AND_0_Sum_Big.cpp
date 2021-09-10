#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

inline void solve() {
    ll n, k; cin >> n >> k;
    ll ans = 1;
    for (int i = 0; i < k; i++) {
        ans = (ans * n) % mod;
    }
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}