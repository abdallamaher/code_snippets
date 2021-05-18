#include <bits/stdc++.h>
using namespace std;
#define ll long long

int const N = 1 << 20;
ll h[N], p[N], need[N];
int n;

inline void solve() {

    for (int i = 0; i < n; i++) need[i] = h[i];
    for (int i = 0; i < n; i++) need[(i + 1) % n] -= p[i];

    ll s = 0;
    for (int i = 0;i < n; i++) {
        need[i] = max(0ll, need[i]);
        s += need[i];
    }

    ll ans = 1e18;
    for (int i = 0; i < n; i++) {
        ans = min(ans, s - need[i] + h[i]);
    }

    printf("%lld\n", ans);

}

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            scanf("%lld %lld", h + i, p + i);
        }
        solve();
    }
}