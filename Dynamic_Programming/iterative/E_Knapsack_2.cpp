#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, sum;
int w[105], v[105];
//      n    val
ll dp[105][100005];

inline void solve() {
    cin >> n >> sum;
    for (int i = 0; i < n; i++)cin >> w[i] >> v[i];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= 100005; j++) { //val
            dp[i][j] = 1e15;
        }
    }
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 100005; j++) { //val
            dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            if (j - v[i - 1] >= 0) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - v[i - 1]] + w[i - 1]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= 100005; i++) {
        if (dp[n][i] <= sum) {
            ans = i;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}