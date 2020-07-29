#include <bits/stdc++.h>
using namespace std;
#define ll long long
string a, b, s;
ll n1, n2;
ll dp[20][10][10][2];

ll solve(int i, int f, int p, int m) {
	if (i == s.length())return f == p;
	ll&ret = dp[i][f][p][m];
	if (~ret)return ret;

	ret = 0;
	if (!m) {
		for (int a = 0; a <= s[i]-'0'; ++a) {
			ret += solve(i + 1, f?f:a, a, m|(a<s[i]-'0'));
		}
	}
	else {
		for (int a = 0; a < 10; ++a) {
			ret += solve(i + 1, f?f:a, a, m);
		}
	}
	return ret;
}
int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> a >> b;
	s = a;
	memset(dp, -1, sizeof(dp));
	n1 = solve(0,0,0,0);
	if (a[0] == a[a.size() - 1])n1--;

	memset(dp, -1, sizeof(dp));
	s = b;
	n2 = solve(0, 0, 0,0);

	cout << n2 - n1 << '\n';
	return 0;
}


