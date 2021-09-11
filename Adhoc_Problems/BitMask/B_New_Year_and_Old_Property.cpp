#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    ll a, b; cin >> a >> b;

    vector<ll> v;
    for (int i = 0; i < 62; i++) {
        ll tmp = 0;
        for (int j = 0; j < i; j++)tmp |= 1ll << j;
        for (int j = i + 1; j < 62; j++) {
            tmp |= 1ll << j;
            v.push_back(tmp);
        }
    }
    sort(v.begin(), v.end());
    
    auto x = lower_bound(v.begin(), v.end(), a);
    auto y = upper_bound(v.begin(), v.end(), b);
    cout << (y - x) << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}