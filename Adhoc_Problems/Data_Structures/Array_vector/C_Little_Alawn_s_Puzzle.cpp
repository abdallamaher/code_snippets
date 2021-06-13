#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;


inline void solve() {
    int n; cin >> n;
    int a[n + 5], b[n + 5], pos[n + 5] = {}, vis[n + 5] = {};
    for (int i = 1; i <= n; i++)scanf("%d", a + i), pos[a[i]] = i;
    for (int i = 1; i <= n; i++)scanf("%d", b + i);

    ll ans = 1;
    for (int i = 1; i <= n; i++) if (!vis[i]) {
        int cur = i;
        while (!vis[cur]) {
            vis[cur] = 1;
            cur = b[pos[cur]];
        }
        ans = (ans + ans) % mod;
    }
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}