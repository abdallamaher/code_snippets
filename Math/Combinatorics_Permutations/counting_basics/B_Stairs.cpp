#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    ll n; cin >> n;
    int cnt = 0;
    vector<ll> v;
    for (int i = 0; i < 31; i++) {
        ll x = 1ll << i;
        v.push_back(x * x);
        if (i)v[i] += 2ll * v[i - 1];
        if (n >= v[i]) {
            cnt++;
            n -= v[i];
        }
    }
    cout << cnt << endl;
}

ll cal(ll x) {
    return x * (x - 1) / 2;
}

void go() {
    ll n; cin >> n;
    int cnt = 0;
    for (int i = 1; cal(1ll << i) <= n;i++) {
        cnt++;
        n -= cal(1ll << i);
    }
    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)go();
}