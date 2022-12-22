#include <bits/stdc++.h>
#ifdef DEBUG
#include "./../competitive_programming/debug.h"
#else
#define debug(...) 42
#endif
using namespace  std;
#define ll long long

inline void solve() {
    int n, m; cin >> n >> m;
    int n2 = 0, n5 = 0;
    ll tmp_n = n;
    while (n > 0 && n % 2 == 0)n /= 2, n2++;
    while (n > 0 && n % 5 == 0)n /= 5, n5++;
    ll k = 1;
    while (n2 < n5 && k * 2 <= m) n2++, k *= 2;
    while (n5 < n2 && k * 5 <= m)n5++, k *= 5;
    while (k * 10 <= m)k *= 10;

    if (k == 1) {
        cout << tmp_n * m << endl;
    }
    else {
        debug(tmp_n, k, (m / k));
        cout << tmp_n * k * (m / k) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}