#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int t; cin >> t;
    while (t--) {
        int n; scanf("%d", &n);
        vector<int> s(200);
        for (int i = 1; i <= n; i++) {
            int x; scanf("%d", &x);
            s[x]++;
        }
        int o = 0, c = 0;
        for (int i = 1, j = 0; i < 200; i++, ++j) {
            if (s[j]) {
                int x = min(s[i], s[j]);
                s[j] -= x;
                s[i] -= x;
                c += x;
            }
            o += s[j] * (j & 1);
        }
        // skip check even as n(even) - o(even) = e(even)
        puts((o%2==0 || ( o-bool(c>0) )%2==0) ? "YES" : "NO");
    }

    return 0;
}