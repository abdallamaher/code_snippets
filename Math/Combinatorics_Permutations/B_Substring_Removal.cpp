#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 998244353;

int main() {
    int n; string s; cin >> n >> s;
    ll c1 = 1, c2 = 1;
    for (int i = 1; i < n;i++) {
        if (s[i] == s[i - 1])c1++;
        else break;
    }

    for (int i = n - 2; i >= 0; i--) {
        if (s[i] == s[i + 1])c2++;
        else break;
    }

    ll ans = 0;
    if (s[0] == s[n - 1])
        ans = (1ll * (c1 + 1) * (c2 + 1)) % mod;
    else
        ans = c1 + c2 + 1;
    cout << ans << endl;
    return 0;
}