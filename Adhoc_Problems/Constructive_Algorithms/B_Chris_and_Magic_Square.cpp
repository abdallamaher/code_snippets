#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

const int N = 1000;
ll g[N][N];
int n;

inline set<ll> go() {
    vector<ll> r(n + 1), c(n + 1);
    ll x = 0, y = 0;
    for (int i = 1; i <= n;i++) {
        for (int j = 1; j <= n; j++) {
            r[i] += g[i][j];
            c[j] += g[i][j];

            if (i == j)x += g[i][j];
            if (i + j == n + 1)y += g[i][j];
        }
    }
    set<ll> s;
    s.insert(x);
    s.insert(y);
    for (int i = 1; i <= n;i++) {
        s.insert(r[i]);
        s.insert(c[i]);
    }
    return s;
}

int main() {
    cin >> n;
    int zi = 0, zj = 0;
    for (int i = 1; i <= n;i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%lld", &g[i][j]);
            if (g[i][j] == 0)zi = i, zj = j;
        }
    }
    set<ll> s = go();
    g[zi][zj] = *(++s.begin()) - *s.begin();
    s = go();

    if (n == 1)cout << 1;
    else if (s.size() == 1)cout << g[zi][zj];
    else cout << -1;
}