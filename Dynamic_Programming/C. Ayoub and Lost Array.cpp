#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, l, r;
const int N = 2e5 + 5, Mod = 1e9 + 7;
int ar[N];
ll dp[N][3];

int f[3];
int getF(int i, int n) {
	if (!i)return n / 3;
	return n / 3 + (n % 3 >= i ? 1 : 0);
}

int table() {
	cin >> n >> l >> r;
	for (int i = 0; i < 3; i++)f[i] = getF(i, r) - getF(i, l - 1);
	// cout << f[0] << f[1] << f[2] << endl;
	dp[0][0] = 1;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				ll cur = dp[i][j];
				ll& nxt = dp[i + 1][(k + j) % 3];
				nxt += cur * f[k];
				nxt %= Mod;
			}
		}
	}
	cout << dp[n][0];
	return 0;
}

ll solve(int i, int rem) {
	rem %= 3;
	if (i == n)return !rem;
	ll&ret = dp[i][rem];
	if (~ret)return ret;

	ret = 0;
	for(int k=0; k<3; k++)
		ret = (ret + solve(i + 1, rem + k) * f[k]) % Mod;
	return ret;
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> l >> r;
	for(int i=0; i<3; i++)f[i] = getF(i, r) - getF(i, l - 1);

	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0);
	return 0;
}
