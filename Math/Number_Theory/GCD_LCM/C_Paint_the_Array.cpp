#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    vector<ll> v(n);
    for (int i = 0;i < n; i++)cin >> v[i];
    ll g1 = 0, g2 = 0;
    for (int i = 0; i < n; i++) {
        if (i & 1)g2 = __gcd(g2, v[i]);
        else g1 = __gcd(g1, v[i]);
    }
    int ok = 1;
    for (int i = 1; i < n; i += 2) {
        if (v[i] % g1 == 0)ok = 0;
    }
    if (ok) {
        cout << g1 << endl;
        return;
    }
    ok = 1;
    for (int i = 0; i < n; i += 2) {
        if (v[i] % g2 == 0)ok = 0;
    }
    if (ok) {
        cout << g2 << endl;
        return;
    }
    cout << 0 << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}