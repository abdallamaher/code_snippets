#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n, m; cin >> n >> m;
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        int type1 = i;  // one expert + two newbies
        int nn = n - i;
        int mm = m - i * 2;
        if (mm >= 0) {
            int type2 = min(nn / 2, mm);  // two expert + one newbies
            ans = max(ans, type1 + type2);
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}