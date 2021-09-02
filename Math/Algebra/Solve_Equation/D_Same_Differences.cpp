#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    vector<int> ar(n);
    for (auto& it : ar)cin >> it;
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        mp[ar[i - 1] - i]++;
    }
    ll ans = 0;
    for (auto& [key, val] : mp) {
        ans += 1ll * val * (val - 1) / 2;
    }
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}