#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    ll n; cin >> n;
    unsigned ll ans = 0;
    for (int i = 3, cnt = 1; i <= n; i += 2, cnt++) {
        ans += 1ll * cnt * (2 * i + 2 * (i - 2));
        // ans += 1ll * cnt * 4 * (i - 1);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}