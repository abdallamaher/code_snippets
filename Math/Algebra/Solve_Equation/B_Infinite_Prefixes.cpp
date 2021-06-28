#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n, x; scanf("%d%d", &n, &x);
    string s; cin >> s;
    int z = 0, o = 0;
    for (auto it : s)if (it == '0')z++;else o++;

    int ans = 0;
    // x       = k  * t + r
    // x - r   = k * t
    int t = z - o, r = 0;

    for (int i = 0; i < n; i++) {
        if (t == 0 && r == x) {
            puts("-1");
            return;
        }

        if (t && abs(x - r) % abs(t) == 0 &&
            (x - r) / t >= 0)ans++;


        if (s[i] == '0')r++;
        else r--;
    }
    printf("%d\n", ans);
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}