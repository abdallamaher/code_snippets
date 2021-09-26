#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, sum;
const int N = 1e7 + 5;
int w[N], v[N];
// take,leave    val
int dp[2][N];

inline void solve() {
    cin >> sum >> n;
    for (int i = 1; i <= n; i++)cin >> v[i] >> w[i];

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) { // sum
            // clear only two rows that we need
            dp[0][j] = dp[1][j];
            dp[1][j] = 0;

            //calc take or leave
            if (j - w[i] >= 0) {
                dp[1][j] = max(dp[0][j], dp[0][j - w[i]] + v[i]);
            }
            else {
                dp[1][j] = dp[0][j];
            }
            ans = max(ans, dp[1][j]);
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