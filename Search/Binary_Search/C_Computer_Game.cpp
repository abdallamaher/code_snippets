#include <bits/stdc++.h>
using namespace std;
#define ll long long


inline void solve() {
    int k, n, a, b;
    scanf("%d %d %d %d", &k, &n, &a, &b);
    if (1ll * min(a, b) * n >= k) {
        cout << -1 << endl;
        return;
    }
    int ans = 0;
    ll st = 0, en = n, mid;
    while (st <= en) {
        mid = (st + en) / 2;
        ll f = mid * a;
        ll s = (n - mid) * b;
        if (f + s < k) {
            ans = mid;
            st = mid + 1;
        }
        else {
            en = mid - 1;
        }
    }
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}