#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
int n, m, d;
ll dp[11000][3];

ll dfs(int sum, int f) {
	if (sum > n)return 0;
	if (sum == n && f)return 1;

	ll& ret = dp[sum][f];
	if (~ret)return ret;
	ret = 0;

	for (int x = 1; x <= m; x++) {
		ret += dfs(sum + x, f | (d <= x));
		if (ret > mod)ret -= mod;
	}
	return ret;
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> d;
	memset(dp, -1, sizeof(dp));
	cout << dfs(0, 0);
	return 0;
}
