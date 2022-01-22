#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    ll l, r; cin >> l >> r;
    if (l & 1) l++;
    if (r - l < 2) {
        cout << -1 << endl;
        return;
    }
    printf("%lld %lld %lld\n", l, l + 1, l + 2);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}