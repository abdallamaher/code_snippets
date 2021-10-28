#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n, m; cin >> n >> m;
    int ar[m + 1] = {};
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        ar[x % m]++;
    }

    int ans = 0;
    for (int i = 0; i <= m - i; i++) {
        int mx = max(ar[i], ar[m - i]);
        int mn = min(ar[i], ar[m - i]);
        
        if (mx == 0)continue;

        if (!i) ans++;
        else ans += max(1, mx - mn);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}