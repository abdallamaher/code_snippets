#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
int dp[27][27];

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		int len = s.length();
		int l = s[0] - 'a';
		int r = s[len - 1] - 'a';
		for (int i = 0; i < 26; i++) {
			if (dp[i][l]) dp[i][r] = max(dp[i][r], dp[i][l] + len);
		}
		dp[l][r] = max(dp[l][r], len);
	}
	int ans = 0;
	for (int i = 0; i < 26; i++) {
		ans = max(ans, dp[i][i]);
	}
	cout << ans << '\n';
	return 0;
}