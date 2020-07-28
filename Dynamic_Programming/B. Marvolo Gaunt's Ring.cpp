#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
const int N = 1e5 + 5;
const ll OO = 3e18 + 7;
ll ar[N];
ll f[6];
ll dp[N][6];

ll solve(int i, int j) {
	if (i > n)return j == 4 ? 0 : -OO;
	ll&ret = dp[i][j];
	if (ret != -OO)return ret;

	ret = solve(i + 1, j);
	
	ret = max(ret, solve(i, j + 1) + ar[i] * f[j]);

	return ret;
}
int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> f[1] >> f[2] >> f[3];
	for (int i = 1; i <= n; i++)cin >> ar[i];

	/*for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= 4; j++) {
			dp[i][j] = -OO;
		}
	}
	cout << solve(1, 1) << '\n';*/


	for (int i = 0; i <= 3; i++)dp[0][i] = -OO;

	for (int j = 1; j <= 3; ++j) {
		for (int i = 1; i <= n; i++) {
			ll a = dp[i - 1][j];
			ll b = dp[i][j - 1] + f[j] * ar[i];
			dp[i][j] = max(a, b);
		}
	}
	cout << dp[n][3] << '\n';
	return 0;
}

