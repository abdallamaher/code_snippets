#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n, l, r; cin >> n >> l >> r;
    vector<int> ar(n);
    for (auto& it : ar)cin >> it;

    sort(ar.begin(), ar.end());
    ll ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (ar[i] > r)break;
        int f = l - ar[i];
        int s = r - ar[i];

        auto p = lower_bound(ar.begin() + i + 1, ar.end(), f) - ar.begin();
        int pp = upper_bound(ar.begin() + i + 1, ar.end(), s) - ar.begin();
        pp--;

        ans += pp - p + 1;
    }
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}