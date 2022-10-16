#include <bits/stdc++.h>
#ifdef DEBUG
#include "./../competitive_programming/debug.h"
#else
#define debug(...) 42
#endif
using namespace  std;
#define ll long long

int fac(int i) {
    int res = 0;
    while (i && i % 2 == 0) {
        res++;
        i /= 2;
    }
    return res;
}

inline void solve() {
    int n; cin >> n;
    ll have = 0;
    ll canS = 0;
    vector<int> canV;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        have += fac(x);
        int can = fac(i);
        canS += can;
        canV.push_back(can);
    }
    if (have + canS < n) {
        cout << -1 << endl;
        return;
    }
    ll need = max(0ll, n - have);
    int res = 0;
    sort(canV.begin(), canV.end());
    // debug(canV);
    while (need) {
        need = max(0ll, need - canV.back());
        canV.pop_back();
        res++;
    }
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}