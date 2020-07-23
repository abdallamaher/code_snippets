#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
const int N = 1e5 + 5;
int dp[N][2][2];
int solve(int i=0, int a=0, int b=0) {
	if (i == s.length())return 0;
	int&ret = dp[i][a][b];
	if (~ret)return ret;
	ret = solve(i + 1, a, b);
	if (s[i] == 'A' && s[i + 1] == 'B' && !a) {
		ret = max(ret, solve(i + 2, 1, b) + 1);
	}
	if (s[i] == 'B' && s[i + 1] == 'A' && !b) {
		ret = max(ret, solve(i + 2, a, 1) + 1);
	}
	return ret;
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> s;
	memset(dp, -1, sizeof(dp));
	cerr << solve() << endl;
	cout << (solve() == 2 ? "YES" : "NO");
	return 0;
}
