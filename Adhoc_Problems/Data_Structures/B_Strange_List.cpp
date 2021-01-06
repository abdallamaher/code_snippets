#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n, k; cin >> n >> k;
    vector<pair<ll, ll>> v;
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        v.push_back({ x, 1 });
    }
    for (int i = 0; i < v.size(); i++) {
        if (v[i].first % k == 0)
            v.push_back({ v[i].first / k, v[i].second * k });
        else break;
    }
    ll ans = 0;
    for (int i = 0; i < v.size(); i++) {
        ans += v[i].first * v[i].second;
    }
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}