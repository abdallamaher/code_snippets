#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pl pair<ll, ll>
#define f first
#define s second

pl inter(pl A, pl B) {
    if (A.s < B.f || B.s < A.f)return { -1, -1 };
    return { max(A.f, B.f), min(A.s, B.s) };
}

inline void solve() {
    ll n, k; scanf("%lld %lld", &n, &k);
    ll H[n] = {};
    for (int i = 0; i < n; i++)scanf("%lld", H + i);
    pl cur = { H[0], H[0] + k };
    for (int i = 1; i < n; i++) {
        cur.f -= k - 1; cur.s += k - 1;
        pl nxt = { H[i], H[i] + 2 * k - 1 };
        cur = inter(cur, nxt);
        if (cur.s - cur.f < k) {
            cout << "NO\n";
            return;
        }
    }
    if (cur.f <= H[n - 1] && cur.s >= H[n - 1] + k) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}