#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

inline void solve() {
    int n; string s;
    cin >> n >> s;
    int p = 0;
    while (s.size() < n) {
        int len = s.size() - p - 1;
        int cnt = s[p] - '0' - 1;
        while (cnt--) {
            s += s.substr(p + 1, len);
        }
        p++;
    }

    ll ans = s.size();
    while (p < n) {
        int len = ans - p - 1;
        if (len < 0) len += mod;
        int cnt = s[p] - '0' - 1;
        ans = (ans + (1ll * cnt * len) % mod) % mod;
        p++;
    }

    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}