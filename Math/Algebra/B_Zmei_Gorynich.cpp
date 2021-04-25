#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n, x; scanf("%d %d", &n, &x);
    int mx = 0, lst = 0;
    for (int i = 0; i < n; i++) {
        int a, b; scanf("%d %d", &a, &b);
        mx = max(a - b, mx);
        lst = max(lst, a);
    }
    if (lst >= x) {
        puts("1");
        return;
    }
    if (mx == 0) {
        puts("-1");
        return;
    }
    int ans = (x - lst + mx - 1) / mx + 1;
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}