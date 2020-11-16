#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n, k; scanf("%d%d", &n, &k);
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    map<int, int> mp;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] % k == 0)continue;
        mp[k - (v[i] % k)]++;
        mx = max(mx, mp[k - (v[i] % k)]);
    }
    ll x = 0;
    for (auto it : mp) {    // mp is sorted
        if (it.second == mx) {
            x = it.first + 1;
            x += 1ll * k * (it.second - 1);
        }
    }
    cout << x << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}