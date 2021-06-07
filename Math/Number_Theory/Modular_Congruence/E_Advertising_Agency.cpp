// best example for modInverse      nCr % mod
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int N = 1e3 + 5;
int nCk[N][N];

ll power(int n, int p) {
    ll res = 1;
    while (p) {
        if (p & 1)res = (res * n) % mod;
        p >>= 1;
        n = (1ll * n * n) % mod;
    }
    return res;
}

ll fact(int n) {
    ll res = 1;
    for (int i = 1; i <= n; i++) {
        res = (res * i) % mod;
    }
    return res;
}

int ncr(int n, int k) {
    return 1ll * fact(n)
        * power(fact(k), mod - 2) % mod
        * power(fact(n - k), mod - 2) % mod;
}

inline void solve() {
    int n, m; scanf("%d %d", &n, &m);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        mp[-x]++;
    }
    ll ans = 0;
    for (auto i = mp.begin(); i != mp.end(); i++) {
        int x = (*i).second;
        if (x >= m) {
            // ans += ncr(x, m);
            // ans %= mod;
            ans = nCk[x][m] % mod;
            break;
        }
        else {
            m -= x;
        }
    }
    cout << ans << endl;
}

void build_nCk() {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            if (j == 0)nCk[i][j] = 1;
            else if (i == 0)nCk[i][j] = 0;
            else nCk[i][j] = (nCk[i - 1][j - 1] + nCk[i - 1][j]) % mod;
        }
}

int main() {
    build_nCk();
    int t; cin >> t;
    while (t--)solve();
}