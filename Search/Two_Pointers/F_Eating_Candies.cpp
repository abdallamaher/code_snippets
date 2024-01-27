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
    for (auto& it : ar)cin >> it;
    // map<int, int> mp_l;
    // map<int, int> mp_r;
    int sum_l = 0, sum_r = 0;
    int i = 0, j = n - 1;
    int mx = 0;
    while (i <= j) {
        if (sum_l + ar[i] < sum_r + ar[j]) {
            sum_l += ar[i];
            // mp_l[sum_l] = i + 1;
            i++;
        }
        else {
            sum_r += ar[j];
            // mp_r[sum_r] = n - j;
            j--;
        }
        if (sum_l == sum_r) {
            mx = i + n - j - 1;
        }
        debug(i, j, sum_l, sum_r);
    }
    // for (auto& it : mp_r) {
    //     if (mp_l[it.first]) {
    //         mx = max(mx, mp_l[it.first] + it.second);
    //     }
    // }
    cout << mx << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}