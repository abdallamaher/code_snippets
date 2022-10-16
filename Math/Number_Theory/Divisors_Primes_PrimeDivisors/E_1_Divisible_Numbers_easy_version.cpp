#include <bits/stdc++.h>
#ifdef DEBUG
#include "./../competitive_programming/debug.h"
#else
#define debug(...) 42
#endif
#define dd debug
using namespace  std;
#define ll long long

inline void solve() {
    ll st1, st2, en1, en2; cin >> st1 >> st2 >> en1 >> en2;
    ll down = st1 * st2;
    for (ll x = st1 + 1; x <= en1; x++) {
        ll rem = down / __gcd(down, x);
        ll y = rem;
        while (y <= st2) {
            y += rem;
        }
        
        if (st2 < y && y <= en2) {
            cout << x << ' ' << y << endl;
            return;
        }
    }
    cout << "-1 -1" << endl;

}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}