#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5 + 5;
int w[N], v[N];
ll dp[N][105];
ll n, rem, ans;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> rem;
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }

    memset(dp, -1, sizeof(dp));

    dp[rem][0] = 0;
    if (rem >= w[0]) {
        dp[ rem - w[0] ][0] = v[0];
    }

    for (int c = 1; c < n; c++) {
        for (int r = 0; r <= rem; r++) {
            if (dp[r][c - 1] != -1) {
                // take
                if (r >= w[c]) {
                    dp[ r - w[c] ][c] = max(dp[r][c - 1] + v[c], dp[r - w[c]][c]);
                    //ans = max(ans, dp[ r - w[c] ][c]);
                }
                //leave
                dp[r][c] = max(dp[r][c], dp[r][c - 1]);
            }
        }
    }
    for (int r = 0; r <= rem; r++) {
        ans = max(ans, dp[r][n - 1]);
    }
    cout << ans;
    return 0;
}