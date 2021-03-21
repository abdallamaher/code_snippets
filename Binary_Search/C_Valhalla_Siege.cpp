#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    ll n, q;
    scanf("%lld %lld", &n, &q);
    vector<ll> ar(n + 1);
    for (int i = 1;i <= n; i++) {
        scanf("%lld", &ar[i]);
        ar[i] += ar[i - 1];
    }
    ll cur = 1, s = 0;
    while (q--) {
        int ans = 0;
        ll r; scanf("%lld", &r);
        s += r;
        auto p = upper_bound(ar.begin() + cur, ar.end(), s) - ar.begin();
        if (p == n + 1) {
            ans = n;
            cur = 1;
            s = 0;
        }
        else {
            ans = n - p + 1;
            cur = p;
        }
        printf("%d\n", ans);
    }
}