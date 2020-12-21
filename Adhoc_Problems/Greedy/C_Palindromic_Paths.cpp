#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &g[i][j]);
        }
    }
    vector<int> ones(n + m + 20), zeros(n + m + 20);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ones[i + j] += g[i][j];
            zeros[i + j] += (1 - g[i][j]);
        }
    }
    int ans = 0;
    for (int i = 0, j = m + n - 2; i < j; j--, i++) {
        ans += min(abs(ones[i] + ones[j]), abs(zeros[i] + zeros[j]));
    }
    printf("%d\n", ans);
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}