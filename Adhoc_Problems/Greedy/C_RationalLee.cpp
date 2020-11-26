#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n, k; scanf("%d%d", &n, &k);
    vector<int> v(n), sizes(k);
    for (int i = 0; i < n; i++)scanf("%d", &v[i]);
    sort(v.begin(), v.end());

    for (int i = 0; i < k; i++)scanf("%d", &sizes[i]);
    sort(sizes.begin(), sizes.end());

    ll ans = 0;
    for (int i = 0; i < k; i++) {
        if (sizes[i] > 1)ans += v[n - 1 - i];
        else ans += v[n - 1 - i] * 2;
    }

    for (int i = k - 1, j = 0; i >= 0; i--) {
        if (sizes[i] > 1) {
            ans += v[j];
            j += sizes[i] - 1;
        }
    }

    printf("%lld\n", ans);
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}