#include <bits/stdc++.h>
#ifdef DEBUG
#include "./../competitive_programming/debug.h"
#else
#define debug(...) 42
#endif
using namespace  std;
#define ll long long

inline void solve() {
    int n, m; cin >> n >> m;
    map<int, vector<int> > mp;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        mp[x].push_back(i);
    }
    for (auto& it : mp) {
        sort(it.second.begin(), it.second.end());
    }
    while (m--)
    {
        int a, b; cin >> a >> b;
        if (mp.count(a) && mp.count(b)) {
            // debug(a, b, mp[a], mp[b]);
            int d = mp[b].size();
            cout << (mp[a][0] <= mp[b][d - 1] ? "YES" : "NO") << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}