#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long

vector<int> good;
ll POWER(ll n, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1)res *= n;
        p /= 2;
        n *= n;
    }
    return res;
}
void build() {
    for (ll mask = 0; mask < (1ll << 10); mask++) {
        ll num = 0;
        for (int i = 0; i < 10; i++) {
            if (mask & (1ll << i))num += POWER(3, i);
        }
        good.push_back(num);
    }
    sort(good.begin(), good.end());
}
inline void solve() {
    ll x; cin >> x;
    cout << *lower_bound(good.begin(), good.end(), x) << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    build();
    while (t--)solve();
}