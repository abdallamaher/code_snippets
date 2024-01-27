#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int w, h, n;cin >> w >> h >> n;
    ll ans = 1;
    while (w % 2 == 0 || h % 2 == 0) {
        ans *= 2;
        if (w % 2 == 0)w /= 2;
        else if (h % 2 == 0)h /= 2;
    }
    //cout << ans << ' ' << n << endl;
    puts(ans >= n ? "YES" : "NO");
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}