#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int a, b; cin >> a >> b;
    int ans = 0;
    while (a < b) {
        ans += b - a;
        a /= 10, b /= 10;
    }
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}