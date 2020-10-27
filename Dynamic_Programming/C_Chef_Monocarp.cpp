#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int N = 2e2 + 5;
int ar[N];
int dp[N][2 * N];
int n;

int solve(int i = 0, int s = 0) {
	if (i == n)return 0;
	int& ret = dp[i][s];
	if (~ret)return ret;

	ret = 1e9;
	for (int j = s + 1; j <= 2 * n; j++) {
		ret = min( ret, solve(i + 1, j) + abs(ar[i] - j) );
	}
	return ret;
}

int main() {
	int t; cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			scanf("%d", &ar[i]);
		}
		sort(ar, ar + n);
		memset(dp, -1, sizeof(dp));
		cout << solve() << '\n';
	}

	return 0;
}