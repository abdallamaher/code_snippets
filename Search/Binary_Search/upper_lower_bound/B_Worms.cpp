#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    ll ar[n] = {};
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        if (i)ar[i] += ar[i - 1];
    }
    int q;  cin >> q;
    while (q--) {
        ll x; cin >> x;
        cout << (lower_bound(ar, ar + n, x) - ar + 1) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}