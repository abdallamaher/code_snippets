#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
int sum[55];
int ar[55];
int dp[55][2];
int solve(int i, int player = 0) {
	if (i > n)return 0;
	int&ret = dp[i][player];
	if (~ret)return ret;

	int a = solve(i + 1, player);

	int b = sum[i + 1] - solve(i + 1, player ^ 1) + ar[i];

	return ret = max(a, b);
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> ar[i];
	}
	for (int i = n; i >= 1; i--) {
		sum[i] = sum[i + 1] + ar[i];
	}

	/*memset(dp, -1, sizeof(dp));
	int bob = solve(1, 0);*/

	
	int dp[55] = { 0 };
	for (int i = n; i >= 1; i--) {
		int a = dp[i + 1];
		int b = sum[i + 1] - dp[i + 1] + ar[i];		// if i take you then second player sould get the pre max
		dp[i] = max(a, b);
	}

	int bob = dp[1];
	printf("%d %d\n", sum[1] - bob, bob);
	return 0;
}

