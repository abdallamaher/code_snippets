#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 2e5 + 5;
ll n, a, b;
ll dp[N][2];
string s;

inline void solve() {
    cin >> n >> a >> b >> s;
    s += '0';
    for (auto& c : s)c -= '0';
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1e15;
        dp[i][1] = 1e15;
    }
    dp[0][0] = b;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 1 || s[i - 1] == 1) {
            dp[i][1] = min(dp[i][1], dp[i - 1][0] + 2 * a + 2 * b);
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + a + 2 * b);
        }
        else {
            dp[i][0] = min(dp[i][0], dp[i - 1][0] + a + b);
            dp[i][0] = min(dp[i][0], dp[i - 1][1] + 2 * a + b);

            dp[i][1] = min(dp[i][1], dp[i - 1][0] + 2 * a + 2 * b);
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + a + 2 * b);
        }
    }
    // for (int i = 0; i <= n; i++)cout << min(dp[i][0], dp[i][1]) << ' ';
    // cout << endl;
    cout << dp[n][0] << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}