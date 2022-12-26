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
    reverse(ar.begin(), ar.end());
    int ans = 0, i = 1;
    while(i < n) {
        if(ar[i] == ar[0]) {
            i++;
            continue;
        }
        ans++;
        i*=2;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}