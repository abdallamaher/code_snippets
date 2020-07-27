#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e3 + 5, mod = 998244353;
int n, m, k;
ll dp[N][N];

ll solve(int i, int diff) {
	if (i > n)return diff == k;
	ll&ret = dp[i][diff];
	if (~ret)return ret;

	if (i == 1)return ret = (solve(i + 1, diff) * m) % mod;

	ret = solve(i + 1, diff);
	ret += solve(i + 1, diff + 1) * (m - 1);
	return ret %= mod;
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	/*memset(dp, -1, sizeof(dp));
	cout << solve(1, 0);*/

	dp[1][0] = m;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= min(i, k); j++) {
			dp[i][j] += dp[i - 1][j] + dp[i - 1][j - 1] * (m - 1);
			dp[i][j] %= mod;
		}
	}
	cout << dp[n][k] << '\n';
	return 0;
}

