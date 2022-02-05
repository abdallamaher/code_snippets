#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5 + 5;
int ar[N];

inline void solve() {
    int n, m;cin >> n >> m;
    ll ans = 0;
    for (int i = 0;i < m; i++) {
        cin >> ar[i];
        if (!i)ans += ar[i];
        else if (ar[i - 1] <= ar[i]) {
            ans -= ar[i - 1];
            ans += ar[i];
        }
        else {
            ans += n;
            ans -= ar[i - 1];
            ans += ar[i];
        }
    }
    cout << ans - 1 << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}