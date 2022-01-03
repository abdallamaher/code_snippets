#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll get(int a, int b, int x, int y, int n) {
    int t = min(a - x, n);
    a -= t;
    n -= t;
    t = min(b - y, n);
    b -= t;
    n -= t;
    return 1ll * a * b;
}

inline void solve() {
    int n, a, b, x, y;
    cin >> a >> b >> x >> y >> n;
    cout << min(get(a, b, x, y, n), get(b, a, y, x, n)) << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}