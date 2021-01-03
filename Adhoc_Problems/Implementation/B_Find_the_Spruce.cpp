#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n, m; cin >> n >> m;
    int g[n + n][m + m] = {};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char x; cin >> x;
            g[i][j] = bool(x == '*');
            if (g[i][j] && j)g[i][j] += g[i][j - 1];
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j]) {
                sum++;
                int r = i + 1, c = 1;
                while (r <= n && j - c > 0 && j + c <= m
                    && g[r][j + c] - g[r][j - c - 1] == 2 * c + 1)
                    sum++, r++, c++;
            }
        }
    }
    cout << sum << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}