#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll m, k;
ll p[(int)1e5 + 5] = {};

ll page(ll p, ll i) {
    return (p - i + k - 1) / k;
}

int main() {
    scanf("%lld %lld %lld", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf("%lld", p + i);
    }
    int ans = 0;
    int i = 0;
    while (i < m) {
        ans++;
        int j = i;
        while (j < m && page(p[i], i) == page(p[j], i))j++;
        i = j;
    }
    cout << ans << endl;
}