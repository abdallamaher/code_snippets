#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        mp[x]++;
    }
    auto f = mp.begin();
    auto l = mp.rbegin();
    
    int mx = 0;
    ll cnt = 1ll * (l->second - 1) * l->second / 2;
    if (mp.size() > 1) {
        mx = l->first - f->first;
        cnt = 1ll * l->second * f->second;
    }
    cout << mx << ' ' << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}