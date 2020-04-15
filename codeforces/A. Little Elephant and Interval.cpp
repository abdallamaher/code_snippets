#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;

ll r, l, ans;

bool ok(ll n) {
    int t = n % 10;
    while (n / 10)n /= 10;
    return t == n;
}

int main() {
    cin.sync_with_stdio(false);
    cin >> l >> r;
    while (l % 10 && l <= r) {
        ans += ok(l);
        l++;
    }
    while (r % 10 && l <= r) {
        ans += ok(r);
        r--;
    }
    //printf("%lld %lld %lld\n", l, r, ans);
    cout << (r - l) / 10 + ans;
    return 0;
}

