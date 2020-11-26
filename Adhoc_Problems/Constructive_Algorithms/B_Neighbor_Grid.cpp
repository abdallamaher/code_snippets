#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m;
bool cornar(int r, int c) {
    if ((r == 0 && c == 0)
        || (r == n - 1 && c == 0)
        || (r == 0 && c == m - 1)
        || (r == n - 1 && c == m - 1))return 1;
    return 0;
}

bool border(int r, int c) {
    if (r == 0 || c == 0 || r == n-1 || c == m-1)return 1;
    return 0;
}

inline void solve() {
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m));
    int ok = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (cornar(i, j) && g[i][j] > 2)ok = 0;
            else if (cornar(i, j))g[i][j] = 2;

            else if (border(i, j) && g[i][j] > 3)ok = 0;
            else if (border(i, j))g[i][j] = 3;

            else if (g[i][j] > 4)ok = 0;
            else g[i][j] = 4;
        }
    }
    if (ok) {
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << g[i][j] << ' ';
            }cout << '\n';
        }
    }
    else cout << "NO\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}