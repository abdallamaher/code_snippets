#include <bits/stdc++.h>
using namespace std;
#define ll long long
int p1, p2, n1, m, k, need;
const int N = 1e4 + 7;
int dp[N];
int solve(int rem = 0) {
	if (rem >= need)return 0;
	int&ret = dp[rem];
	if (~ret)return ret;

	ret = solve(rem + n1) + p1;
	ret = min(ret, solve(rem + 1) + p2);
	return ret;
}
int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> p1 >> p2 >> n1 >> m >> k;
	need = n1 * m - k;
	memset(dp, -1, sizeof dp);     
	cout << solve();
	return 0;
}


