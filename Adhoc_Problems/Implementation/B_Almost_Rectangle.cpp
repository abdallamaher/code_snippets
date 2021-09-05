#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    char g[n][n] = {};
    set<int> x, y;
    for (int i = 0;i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
            if (g[i][j] == '*') {
                x.insert(i);
                y.insert(j);
            }
        }
    }

    if (x.size() < 2) {
        int xx = *x.begin() + 1;
        if (xx == n)xx = *x.begin() - 1;
        x.insert(xx);
    }
    if (y.size() < 2) {
        int yy = *y.begin() + 1;
        if (yy == n)yy = *y.begin() - 1;
        y.insert(yy);
    }

    for (auto& it : x) {
        int xx = it;
        for (auto& itt : y) {
            int yy = itt;
            g[xx][yy] = '*';
        }
    }

    for (int i = 0;i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << g[i][j];
        }
        cout << '\n';
    }
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}