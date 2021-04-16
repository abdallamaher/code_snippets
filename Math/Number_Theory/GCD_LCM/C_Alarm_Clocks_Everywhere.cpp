#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)scanf("%lld", &a[i]);

    ll g = 0;
    for (int i = 1; i < n; i++) {
        g = __gcd(a[i] - a[i - 1], g);
    }

    for (int i = 0; i < m; i++) {
        ll x; scanf("%lld", &x);
        if (g % x == 0)return 0 * printf("YES\n%lld %d\n", a[0], i + 1);
    }

    puts("NO");
    return 0;
}