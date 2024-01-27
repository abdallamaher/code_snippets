#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    vector<int> ans;
    int cnt = 0;
    for (int i = 19; i >= 0; i--) {
        if ((n >> i & 1) == 0) {
            ans.push_back(i + 1);
            int mask = (1 << i + 1) - 1;
            n ^= mask;
            cnt++;
            if (__builtin_popcount(n) == 20)break;
            n++;
            cnt++;
        }
    }
    cout << cnt << endl;
    for (auto& it : ans)cout << it << ' ';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}