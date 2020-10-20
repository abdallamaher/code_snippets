#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; scanf("%d%d", &n, &m);
        vector<vector<int>> g(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                g[i][j] = (i + j) & 1;
            }
        }
        if ((n * m) % 2 == 0) {
            if (g[0][0])g[0][0] = 0;
            else if (g[0][m - 1])g[0][m - 1] = 0;
            else if (g[n - 1][0])g[n - 1][0] = 0;
            else if (g[n - 1][m - 1])g[n - 1][m - 1] = 0;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << "BW"[g[i][j]];
            }cout << '\n';
        }


        continue;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << "BW"[!i && !j];
            }puts("");
        }
    }
    return 0;
}