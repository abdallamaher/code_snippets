#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    ll n, k; scanf("%lld%lld", &n, &k);

    vector<int> sys(200);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        ll x; scanf("%lld", &x);
        int cur = 0;
        while (x) {
            sys[cur] += x % k;
            cur++;
            x /= k;
        }
        mx = max(cur, mx);
    }

    int ok = 1;
    for (int i = 0; i < mx;i++)ok &= bool(sys[i] <= 1);
    puts(ok ? "YES" : "NO");
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}