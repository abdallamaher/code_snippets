#include <bits/stdc++.h>
#ifdef DEBUG
#include "./../competitive_programming/debug.h"
#else
#define debug(...) 42
#endif
using namespace  std;
#define ll long long


inline void solve() {
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.rbegin(), v.rend());
    for (int i = 1; i < n; i++) {
        v[i] += v[i - 1];
    }
    while (k--) {
        int x; cin >> x;
        auto p = lower_bound(v.begin(), v.end(), x) - v.begin();
        if (p != n) {
            cout << p + 1 << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}