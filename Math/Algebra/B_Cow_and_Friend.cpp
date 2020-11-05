#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n, m; scanf("%d %d", &n, &m);
    int mx = 0;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        mx = max(mx, x);
        v[i] = x;
    }
    if(count(v.begin(), v.end(), m))printf("%d\n", 1);
    else if(mx > m)printf("%d\n", 2);
    else printf("%d\n", (m + mx - 1) / mx);
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}