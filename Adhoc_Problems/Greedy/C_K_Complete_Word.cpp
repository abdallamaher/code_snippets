#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n, k; scanf("%d %d", &n, &k);
    string s; cin >> s;
    int ans = 0;
    for (int i = 0; i < (k + 1) / 2; i++) {
        int all = 0;
        int ar[30] = {};
        for (int j = i, r = k - i - 1; j < n; j += k, r += k) {
            all++;
            ar[s[j] - 'a']++;
            if (r != j) {
                all++;
                ar[s[r] - 'a']++;
            }
        }
        int mx = 0;
        for (auto it: ar)mx = max(mx, it);
        ans += all - mx;
    }
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}