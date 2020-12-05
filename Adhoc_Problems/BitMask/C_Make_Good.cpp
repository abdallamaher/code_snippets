#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    vector<ll> v(n);
    ll xo = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &v[i]);
        sum += v[i];
        xo ^= v[i];
    }
    printf("2\n%lld %lld\n", xo, sum + xo);
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}