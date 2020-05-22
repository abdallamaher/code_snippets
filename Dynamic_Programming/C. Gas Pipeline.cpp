#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 5;
int q, n, a, b;
string s;
ll dp[4][N];
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> q;
    while (q--) {
        cin >> n >> a >> b >> s;
        s += '0';
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j] = 1e16;
            }
        }
        dp[1][0] = b;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '1' && s[i - 1] == '1') {
                dp[2][i] = dp[2][i - 1] + a + 2ll * b;
            }
            else if (s[i] == '1' && s[i - 1] == '0') {
                dp[2][i] = min(dp[1][i - 1] + 2ll * a + 2ll * b, dp[2][i - 1] + a + 2ll * b);
            }
            else if (s[i] == '0' && s[i - 1] == '1') {
                dp[2][i] = dp[2][i - 1] +  a + 2ll * b;
            }
            else if (s[i] == '0' && s[i - 1] == '0') {
                dp[2][i] = min(dp[1][i - 1] + 2ll * a + 2ll * b, dp[2][i - 1] + a + 2ll * b);
                dp[1][i] = min(dp[1][i - 1] + a + b, dp[2][i - 1] + 2ll * a + b);
            }
        }
        cout << dp[1][n] << endl;
    }
    return 0;
}
