#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n, m; cin >> n >> m;
    int ar[n + n] = {};
    int c[m + m] = {};
    for (int i = 0; i < n; i++)scanf("%d", ar + i);
    sort(ar, ar + n);
    reverse(ar, ar + n);
    for (int i = 0; i < m; i++)scanf("%d", c + i);
    ll ans = 0;
    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (idx >= ar[i]) ans += c[ar[i] - 1];
        else ans += c[idx++];
    }
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}