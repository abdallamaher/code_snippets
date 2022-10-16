#include <bits/stdc++.h>
#ifdef DEBUG
#include "./../competitive_programming/debug.h"
#else
#define debug(...) 42
#endif
using namespace  std;
#define ll long long

inline void solve() {
    int n, q; cin >> n >> q;
    ll sum = 0;
    int e = 0, o = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x & 1) o++;
        else e++;
        sum += x;
    }
    int pw_o = 0, pw_e = 0;
    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        if (a) // odd
        {
            sum += 1ll * o * b;
        }
        else {
            sum += 1ll * e * b;
        }
        if (b & 1)  { // odd
            if(a) { // add to odd
                e += o;
                o = 0;
            }
            else {
                o += e;
                e = 0;
            }
        }
        cout << sum << endl;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}