#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, m;
string s, t;
const int mod = 998244353;
const int N = 2e5 + 5;
ll sum[N];
ll power = 1;

int main() {
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m;i++) {
        sum[i] = sum[i - 1] + bool(t[i] == '1');
    }
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        ll a = n - i - 1;
        ll b = m - i - 1;
        if (i < n && s[a] == '1') {
            ans += power * sum[b];
            if (ans > mod)ans %= mod;
        }
        power = (2 * power) % mod;
    }
    cout << ans << endl;
}