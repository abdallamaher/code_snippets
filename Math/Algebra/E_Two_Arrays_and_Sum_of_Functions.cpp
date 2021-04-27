#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 998244353;

int main() {
    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        a[i] = a[i] * (i + 1) * (n - i);
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);


    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        a[i] %= mod;
        ans = (ans + a[i] * b[i]) % mod;
    }
    cout << ans;
}