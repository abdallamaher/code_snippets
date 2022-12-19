#include <bits/stdc++.h>
#ifdef DEBUG
#include "./../competitive_programming/debug.h"
#else
#define debug(...) 42
#endif
using namespace  std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (auto& it : v)cin >> it;
    sort(v.begin(), v.end());
    // build mx
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < 10; j++) {
            if ((v[i] & (1 << j) && !(v[n - 1] & (1 << j)))) {
                v[i] = v[i] ^ (1 << j);
                v[n - 1] = v[n - 1] | (1 << j);
            }
        }
    }
    // build mn
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            if ((v[0] & (1 << j) && !(v[i] & (1 << j)))) {
                v[0] = v[0] ^ (1 << j);
                v[i] = v[i] | (1 << j);
            }
        }
    }
    sort(v.begin(), v.end());
    cout << v[n - 1] - v[0] << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}