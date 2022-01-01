#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    vector<int> a(n * 3), b(n * 3);

    for (int i = 1;i <= n; i++)cin >> a[i];
    for (int i = n; i > 0;i--) {
        a[i] += a[i + 1];
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        b[i] += b[i - 1];
    }

    int ans = 1e9 + 8;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, max(a[i + 1], b[i - 1]));
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}