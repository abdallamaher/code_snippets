#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

ll ncr(int n, int r) {
    ll up = 1, down = 1;
    r = min(r, n - r);
    while (r) {
        up *= n;
        down *= r;

        long long g = __gcd(up, down);
        up /= g;
        down /= g;

        n--;
        r--;
    }
    return up;
}

int main() {
    ll n, m, t; cin >> n >> m >> t;
    ll sum = 0;
    for (int i = 4; i < t; i++) {
        int g = t - i;
        if(g <= m && i <= n) sum += ncr(n, i) * ncr(m, g);
    }
    cout << sum;
}