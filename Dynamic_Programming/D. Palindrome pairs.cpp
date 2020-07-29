#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
const int N = 2e3 + 7;
int dp[N][N];
int sum[N];

int is_pal(int l, int r) {
	if (l > r)return 1;
	if (s[l] != s[r])return 0;
	int&ret = dp[l][r];
	if (~ret)return ret;
	
	return ret = is_pal(l + 1, r - 1);
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	memset(dp, -1, sizeof dp);
	
	cin >> s;
	s = '#' + s;
	int n = s.length();
	for (int i = 1; i < n; ++i) {
		sum[i] += sum[i - 1];		// number of all pairs before + inclusive i
		for (int j = 1; j <= i; ++j) {
			if (is_pal(j, i))sum[i]++;
		}
	}

	ll ans = 0;
	for (int i = 2; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			if (is_pal(i, j))ans += sum[i - 1];
		}
	}
	cout << ans << '\n';
	return 0;
}


