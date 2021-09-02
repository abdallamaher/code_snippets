#include <bits/stdc++.h>
using namespace std;
#define ll long long


inline void go() {
    int n; cin >> n;
    int ans = 0;
    int p = 32 - __builtin_clz(n) - 1;
    cout << (1 << p) - 1 << endl;
}

inline void solve() {
    int n; cin >> n;
    // first bit that is 1 , cout (1 << i) -1
    int ans = 0;
    for (int i = 30; i >= 0; i--) {
        if (n & (1 << i)) {
            ans = (1 << i) - 1;
            break;
        }
    }
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}