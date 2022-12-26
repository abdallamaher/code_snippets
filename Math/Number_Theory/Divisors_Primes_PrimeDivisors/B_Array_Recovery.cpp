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
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    vector<int> ans = ar;
    for (int i = 1; i < n; i++) {
        int x = ans[i - 1] + ar[i];
        int y = ans[i - 1] - ar[i];
        if (x >= 0 && y >= 0 && x != y) {
            cout << -1 << endl;
            return;
        }
        ans[i] = x;
    }
    for (auto& it : ans) {
        cout << it << ' ';
    }
    cout << endl;  
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}