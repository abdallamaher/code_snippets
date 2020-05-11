#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
const int OO = (int)1e9;

ll n, res, ans;
ll gcd(ll a, ll b) {
    return !b ? a : gcd(b, a % b);
}

int main() {
    cin.sync_with_stdio(false);
    cin >> n;
    // get greatest 3 coprime under (n)
    for (int i = max(1ll, n - 100); i <= n; i++) {
        for (int j = max(1ll, n - 100); j <= n; j++) {
            for (int x = max(1ll, n - 100); x <= n; x++) {
                ll ans = 1ll * i * j / gcd(i, j);
                ans = ans * x / gcd(ans, x);
                res = max(ans, res);
            }
        }
    }
    printf("%lld", res);
    return 0;
}










