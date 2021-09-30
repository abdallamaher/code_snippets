#include <bits/stdc++.h>
using namespace std;
#define ll long long

set<int> adj[30];

inline void solve() {
    string str; cin >> str;
    for (int i = 0; i < str.size(); i++) {
        adj[str[i] - 'a'].insert(i);
    }
    int q; cin >> q;
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int pos;char c; cin >> pos >> c;
            pos--;
            adj[str[pos] - 'a'].erase(pos);
            str[pos] = c;
            adj[c - 'a'].insert(pos);
        }
        else {
            int l, r; cin >> l >> r;
            l--, r--;
            int ans = 0;
            for (int i = 0; i < 30; i++) {
                auto p = adj[i].lower_bound(l);
                if (p == adj[i].end())continue;
                ans += bool(*p <= r);
            }
            cout << ans << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}