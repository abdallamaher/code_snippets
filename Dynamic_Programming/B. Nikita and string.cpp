#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
const int N = 5e3 + 7;
int dp[N][4];

int table() {
	cin >> s;
	int ans = 0;
	for (int i = 1; i <= s.length(); i++) {
		for (int j = 1; j < 4; j++) {
			dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]);
			if (s[i - 1] == 'b' && j == 2)dp[i][j]++;
			if (s[i - 1] == 'a' && j != 2)dp[i][j]++;
			
			ans = max(dp[i][j], ans);
		}
	}
	for (int j = 1; j < 4; j++) {
		for (int i = 1; i <= s.length(); i++) {
			cerr << dp[i][j] << ' ';
		}
		cerr << endl;
	}
	cout << ans;
	return 0;
}


int solve(int i = 0, int j = 1) {
	if (i == s.length())return 0;
	int&ret = dp[i][j];
	if (~ret)return ret;

	ret = solve(i + 1, j);
	if (s[i] == 'a') {
		if (j != 2)ret = max(ret, solve(i + 1, j) + 1);
		else ret = max(ret, solve(i + 1, j + 1) + 1);
	}
	else if (j == 2)ret = max(ret, solve(i + 1, j) + 1);
	else if (j == 1) ret = max(ret, solve(i + 1, j + 1) + 1);
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