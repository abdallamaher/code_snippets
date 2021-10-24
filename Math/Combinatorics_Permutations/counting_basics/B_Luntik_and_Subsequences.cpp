#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll  ncr(int n, int r) {
    long long p = 1, k = 1;
    if (n - r < r)
        r = n - r;

    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
            long long m = __gcd(p, k);
            p /= m;
            k /= m;
            n--;
            r--;
        }
    }
    else
        p = 1;

    return p;
}

inline void solve() {
    int n; cin >> n;
    ll ones = 0, zeros = 0;
    for (int i = 0;i < n; i++) {
        int x; cin >> x;
        if (x == 0)zeros++;
        else if (x == 1)ones++;
    }

    ll ans = ones;
    for (int i = 1; i <= zeros; i++) {
        ans += ones * ncr(zeros, i);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}