#include <bits/stdc++.h>
#ifdef DEBUG
#include "./../competitive_programming/debug.h"
#else
#define debug(...) 42
#endif
using namespace  std;
#define ll long long

inline void solve() {
    int n, l, r; cin >> n >> l >> r;
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        int x = l / i * i + (l % i == 0 ? 0 : i);
        if (x > r) {
            cout << "NO" << endl; 
            return;
        }
        ans.push_back(x);
    }
    cout << "YES\n";
    for (auto& it : ans)cout << it << ' ';cout << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}