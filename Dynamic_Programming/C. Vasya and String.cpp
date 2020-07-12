#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, k;
string s;
const int N = 1e5 + 5;
int dp[N], dpa[N];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    cin >> s;
    for (int i = 1; i<=n; i++) {
        if (s[i-1] == 'b')
            dp[i] = dp[i - 1] + 1, dpa[i] = dpa[i - 1];
        else 
            dp[i] = dp[i - 1], dpa[i] = dpa[i - 1] + 1;
    }
    int ans = 0, len = 0;
    for (int i = n; i > 0; i--) {
        int p = lower_bound(dp, dp + n, dp[i] - k + 1) - dp;
        len = i - p + 1;
        int pp = lower_bound(dp, dp + n, dp[p-1]) - dp;
        len += p - pp - 1;
        ans = max(ans, len);
    }

    for (int i = n; i > 0; i--) {
        int p = lower_bound(dpa, dpa + n, dpa[i] - k + 1) - dpa;
        len = i - p + 1;
        int pp = lower_bound(dpa, dpa + n, dpa[p - 1]) - dpa;
        len += p - pp - 1;
        ans = max(ans, len);
    }
    cout << ans << '\n';
    return 0;
}

