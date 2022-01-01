#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; string s; cin >> n >> s;
    map< pair<int, int>, int > vis;
    pair<int, int> cur = { 0, 0 };
    vis[cur] = -1;
    int l = -1, r = n;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'D')cur.first++;
        if (s[i] == 'U')cur.first--;
        if (s[i] == 'L')cur.second++;
        if (s[i] == 'R')cur.second--;
        if (vis.count(cur)) {
            if (i - vis[cur] < r - l) {
                l = vis[cur] + 1;
                r = i;
            }
        }
        vis[cur] = i;
    }
    if (l == -1)cout << -1 << endl;
    else cout << l + 1 << ' ' << r + 1 << endl;
}


int main() {
    int t; cin >> t;
    while (t--)solve();
}