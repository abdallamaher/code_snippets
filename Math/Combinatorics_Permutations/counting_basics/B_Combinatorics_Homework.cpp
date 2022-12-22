#include <bits/stdc++.h>
#ifdef DEBUG
#include "./../competitive_programming/debug.h"
#else
#define debug(...) 42
#endif
using namespace  std;
#define ll long long

inline void solve() {
    int a, b, c, m; cin >> a >> b >> c >> m;
    // build mx
    int big = a + b + c - 3;
    //build mn
    int mx = max({ a,b,c });
    int mn = min({ a,b,c });
    int md = (a + b + c) - (mx + mn);
    int small = mx - (md + mn) - 1;
    if (small <= m && m <= big) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}