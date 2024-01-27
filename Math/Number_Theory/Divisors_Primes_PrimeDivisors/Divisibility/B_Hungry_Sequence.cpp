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
    for (int i = 0, curr = 1000000; i < n; curr++, i++)cout << curr << ' ';
}

inline void go() {
    // if no under 1e7 constain
    const int N = 1e7 + 5;
    vector<int> p;
    vector<int> vis(N, 0);
    for (int i = 2; 1ll * i * i < N; i++) {
        if (vis[i] == 0) {
            p.push_back(i);
            for (int j = i + i; j < N; j += i) vis[j] = 1;
        }
    }
    debug(p.size());
    int n; cin >> n;
    vector<ll> ans;
    for (int i = 0; i < p.size(); i++) {
        for (int j = i + 1; j < p.size(); j++) {
            for (int k = j + 1; k < p.size(); k++) {
                ans.push_back(1ll * p[i] * p[j] * p[k]);

                if (ans.size() > n) {
                    sort(ans.begin(), ans.end());
                    debug(ans.size());
                    for (int x = 0; x < n; x++)
                        cout << ans[x] << ' ';
                    debug(p);
                    debug(ans);
                    return;
                }
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}