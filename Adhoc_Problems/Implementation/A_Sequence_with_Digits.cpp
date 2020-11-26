#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t; cin >> t;
    while (t--) {
        ll n, k; scanf("%lld%lld", &n, &k);
        ll p = n;
        while (--k) {
            ll tmp = n;
            ll mn = 12, mx = 0;
            while (tmp) {
                mn = min(mn, tmp % 10);
                mx = max(mx, tmp % 10);
                tmp /= 10;
            }
            if (!mn)break;
            n += mn * mx;
        }
        printf("%lld\n", n);
    }
    return 0;
}