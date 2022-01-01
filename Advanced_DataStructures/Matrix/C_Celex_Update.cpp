#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int x1, x2, y1, y2; scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    // smallest sum      RRRR DDDDD
    // next   move D before R
    printf("%lld\n", 1ll * (x2 - x1) * (y2 - y1) + 1);
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}