#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e6 + 5;
int W, n, ans;
int v[N], w[N];
int dp[2][N];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> W >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i] >> w[i];
    }
    
    for (int i = 0; i < n; i++) {
        for (int c = 1; c <= W; c++) {
            dp[0][c] = dp[1][c];
            dp[1][c] = 0;

            if (c >= w[i])
                dp[1][c] = max(dp[0][c], dp[0][c-w[i]] + v[i]); // leave or pick 

            else
                dp[1][c] = dp[0][c];    // leave

            ans = max(ans, dp[1][c]);
        }
        /*for (int c = 0; c <= W; c++) {
            cout << dp[0][c] << ' ';
        }cout << '\n';*/
    }
    cout << ans;
    return 0;
}