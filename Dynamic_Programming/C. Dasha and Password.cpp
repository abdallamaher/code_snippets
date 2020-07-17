#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m;
int f[55][3];
string s;


int dpp[55][3][3][3];
int go(int i, int a, int b, int c) {
	if (i == n) {
		return a && b && c ? 0 : 1e9;
	}
	int&ret = dpp[i][a][b][c];
	if (~ret)return ret;
	ret = solve(i + 1, a, b, c);
    for(int j=0; j<)
	if (!a)
		ret = min(solve(i + 1, 1, b, c) + f[i][0], ret);
	if(!b)
		ret = min(solve(i + 1, a, 1, c) + f[i][1], ret);
	if (!c)
		ret = min(solve(i + 1, a, b, 1) + f[i][2], ret);
	return ret;
}

int dp[55][10];
int solve(int i, int msk = 0) {
	if (i == n) {
		return msk == (1 << 3) - 1 ? 0 : 1e9;
	}
	int&ret = dp[i][msk];
	if (~ret)return ret;
	ret = solve(i + 1, msk);
	for (int j = 0; j < 3; j++) {
		if (msk & (1 << j))continue;
		ret = min(ret, solve(i + 1, msk | (1 << j)) + f[i][j]);
	}
	return ret;
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < 55; i++) {
		for (int j = 0; j < 3; j++) {
			f[i][j] = 1000;
		}
	}

	for (int j = 0; j < n; j++) {
		cin >> s;
		s += s[0];

		for (int i = 0; i < m; i++) {
			if (s[i] >= 'a' && s[i] <= 'z')f[j][0] = min(f[j][0], i);
			else if (s[i] >= '0' && s[i] <= '9')f[j][1] = min(f[j][1], i);
			else f[j][2] = min(f[j][2], i);
		}


		for (int i = m; i > 0; i--) {
			if (s[i] >= 'a' && s[i] <= 'z')f[j][0] = min(f[j][0], m - i);
			else if (s[i] >= '0' && s[i] <= '9')f[j][1] = min(f[j][1], m - i);
			else f[j][2] = min(f[j][2], m - i);
		}

	}


	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0);
	return 0;
}