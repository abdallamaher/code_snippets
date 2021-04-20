#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n, k; scanf("%d %d", &n, &k);
    puts(k % n == 0 ? "0" : "2");

    int g[n][n] = {};
    for (int c = 0;c < n && k;c++) {
        for (int r = 0; r < n && k; r++) {
            g[r][(c + r) % n] = 1;
            k--;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0;j < n;j++)
            printf("%d", g[i][j]);
        puts("");
    }
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}
