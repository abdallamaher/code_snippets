#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline int sum(ll x) {
    int res = 0;
    while (x) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

inline void solve() {
    ll n, s; scanf("%lld%lld", &n, &s);
    if (sum(n) <= s) {
        cout << 0 << endl;
        return;
    }
    ll pw = 1, ans = 0;
    for (int i = 0; i < 18; i++) {
        ll digit = (n / pw) % 10;
        ll add = pw * ((10 - digit) % 10);
        n += add;
        ans += add;
        if (sum(n) <= s) {
            break;
        }
        pw *= 10;
    }
    printf("%lld\n", ans);
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}