#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int l, r, d, u; cin >> l >> r >> d >> u;
    int x, y, x1, x2, y1, y2; cin >> x >> y >> x1 >> y1 >> x2 >> y2;

    int ok = 1;
    if(x1 == x2 && (l, r))ok = 0;
    if(y1 == y2 && (u, d))ok = 0;

    int t = min(u, d);  // think of min boarder you reach
    u -= t, d -= t;
    if (u + y > max(y1, y2) || y - d < min(y1, y2))ok = 0;

    t = min(l, r);
    l -= t, r -= t;
    if (r + x > max(x1, x2) || x - l < min(x1, x2))ok = 0;

    cout << (ok ? "Yes" : "No") << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}