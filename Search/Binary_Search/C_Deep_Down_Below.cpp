#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, k;
vector<pair<ll, ll>> caves;

inline bool can(ll x) {
    for (auto& it : caves) {
        if (x <= it.first)return 0;
        x += it.second;
    }
    return 1;
}

inline void solve() {
    caves.clear();
    scanf("%lld", &n);
    for (ll c = 0; c < n; c++) {
        scanf("%lld", &k);
        ll mx = 0;
        for (ll i = 0; i < k; i++) {
            ll p; scanf("%lld", &p);
            mx = max(mx, p - i);
        }
        caves.push_back({ mx, k });
    }
    sort(caves.begin(), caves.end());
    ll st = 0, en = 1e15, mid;
    while (st < en) {
        mid = (st + en) / 2;
        if (can(mid))en = mid;
        else st = mid + 1;
    }
    cout << st << endl;
}

int main() {
    ll t; cin >> t;
    while (t--)solve();
}