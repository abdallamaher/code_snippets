#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
const int N = 2e5 + 7;
ll dp[N][4];

ll solve(int i = 0, int mod = 0) {
	if (i == s.length())return 0;
	ll&ret = dp[i][mod];
	if (~ret)return ret;
	int t = int(s[i] - '0');
	ret = solve(i + 1, 0);
	ret = max(ret, solve(i + 1, (t + mod) % 3));
	if((t + mod) % 3 == 0)
		ret = max(ret, solve(i + 1, 0) + 1);
	return ret;
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> s;
	memset(dp, -1, sizeof(dp));
	cout << solve();
	return 0;
}
