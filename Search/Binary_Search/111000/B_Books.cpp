#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n, k; cin >> n >> k;
    vector<int> v(n + n);
    for (int i = 1;i <= n; i++)cin >> v[i];
    for (int i = 1; i <= n; i++)v[i] += v[i - 1];

    int st = 0, en = n, mid;
    while (st < en) {
        mid = (st + en + 1) / 2;
        int ok = 0;
        for (int i = mid; i <= n; i++) {
            ok |= (v[i] - v[i - mid] <= k);
        }
        if (ok)st = mid;
        else en = mid - 1;
    }
    cout << st << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}