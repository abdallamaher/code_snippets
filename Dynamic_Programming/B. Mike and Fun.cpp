#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, k;
const int N = 5e3 + 5;
int g[N][N];
int dp[N];

inline void update(int x) {
    int mx = 0;
    dp[x] = 0;
    for (int j = 0; j < m; j++) {
        if (g[x][j])mx++;
        else mx = 0;
        dp[x] = max(mx, dp[x]);
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        int mx = 0;
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j])mx++;
            else mx = 0;
            dp[i] = max(mx, dp[i]);
        }
    }

    while (k--) {
        int i, j; cin >> i >> j;
        i--, j--;
        g[i][j] ^= 1;
        update(i);
        cout << *max_element(dp, dp+n) << endl;
    }
    return 0;
}