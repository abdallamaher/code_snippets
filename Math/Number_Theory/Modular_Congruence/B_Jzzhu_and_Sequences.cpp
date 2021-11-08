#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

inline void solve() {
    ll x, y, n; cin >> x >> y >> n;
    n--;
    n %= 6;
    ll ans[] = { x, y, y - x, -x, -y, -y + x };
    while (ans[n % 6] < 0)ans[n % 6] += mod;
    cout << (ans[n % 6] % mod) << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}