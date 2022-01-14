#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n, q; cin >> n >> q;
    vector<int> v(55, 1e9);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        v[x] = min(v[x], i + 1);
    }
    while (q--) {
        int x; cin >> x;
        cout << v[x] << ' ';
        for (int i = 0; i < 55; i++) {
            if (v[i] && v[i] < v[x]) {
                v[i]++;
            }
        }
        v[x] = 1;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}