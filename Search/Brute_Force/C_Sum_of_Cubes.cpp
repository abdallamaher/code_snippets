#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> v;
void build() {
    for (int i = 1; i <= 10000; i++) {
        v.push_back(1ll * i * i * i);
    }
}

inline void solve() {
    ll n; cin >> n;
    int ok = 0;
    for (int i = 0; i < v.size(); i++) {
        ll a = v[i];
        ll b = n - v[i];
        ll x = *lower_bound(v.begin(), v.end(), b);
        if (x == b) ok = 1;
    }
    cout << (ok ? "YES" : "NO") << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    build();
    while (t--)solve();
}