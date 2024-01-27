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
    vector<int> days(n + 5);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        days[x] = i;
    }

    // 
    int cur = n, day = 1;
    while (cur > 0) {
        debug(cur, day);
        while (cur && days[cur] <= day) {
            cout << cur << ' ';
            cur--;
        }
        cout << endl;
        day++;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}