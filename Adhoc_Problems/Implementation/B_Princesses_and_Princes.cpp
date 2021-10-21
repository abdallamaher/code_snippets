#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    int vis[n + 1] = {};
    set<int> st[n + 1] = {};
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        while (x--) {
            int p; cin >> p;
            st[i].insert(p - 1);
        }
    }
    int free = -1;
    for (int i = 0; i < n; i++) {
        int x = 0;
        while (st[i].size()) {
            int f = *st[i].begin();
            st[i].erase(st[i].begin());
            if (vis[f] == 0) {
                vis[f] = 1;
                x = 1;
                break;
            }
        }
        if (x == 0)free = i;
    }
    if (free == -1)cout << "OPTIMAL\n";
    else {
        cout << "IMPROVE\n";
        for (int i = 0; i < n; i++) if (vis[i] == 0) {
            cout << free + 1 << ' ' << i + 1 << endl;
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}