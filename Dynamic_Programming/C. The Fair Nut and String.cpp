#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
const int N = 1e5 + 5, mod = 1e9 + 7;
ll dp[N][2][2];
int sum[N];

ll solve(int i, int a, int b) {
	if (i == s.length())return a;
	ll&ret = dp[i][a][b];
	if (~ret)return ret;

	ret = solve(i + 1, a, b | s[i] == 'b');
	if (s[i] == 'a' && b)
		ret += solve(i + 1, 1, 0);
	return ret %= mod;
}

void go() {
	int cnt = 0;
	int ar[N] = { 0 };
	for (auto c : s) {
		if (c == 'a')  ar[cnt]++;
		else if (c == 'b') cnt++;
	}

	ll ans = 1;
	for (int i = 0; i <= cnt; i++) {
		ans = (ans * (ar[i] + 1)) % mod;
	}

	cout << ans - 1;
}


int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> s;

	/*memset(dp, -1, sizeof(dp));
	cout << solve(0, 0, 1);*/

	//go();




	s = '#' + s;
	ll dp[N] = { 0 }; int b = 0; 
	for (int i = 1; s[i]; i++) {
		dp[i] = dp[i - 1];
		if (s[i] == 'b') b = i;
		else if (s[i] == 'a') {
			dp[i] = (dp[i - 1] + dp[b] + 1) % mod;
		}
	}
	cout << dp[s.length()-1] << '\n';
	return 0;
}

