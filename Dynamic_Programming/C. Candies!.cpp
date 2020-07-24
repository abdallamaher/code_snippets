#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
int ar[N];
int n, q, l, r;
pair<int, int> dp[20][N];


int log_f(ll x) {
	int c = 0;
	while (x)x >>= 1, c++;
	return c - 1;
}
int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		dp[0][i].first = ar[i];			// building table
	}
	for (int p = 1; p <= log_f(n); p++) {
		int len = 1 << (p - 1);
		for (int i = 0; i+len < n; i++) {
			dp[p][i].first = dp[p - 1][i].first + dp[p - 1][i + len].first;
			dp[p][i].second = dp[p - 1][i].second + dp[p - 1][i + len].second;

			if (dp[p][i].first >= 10) {
				dp[p][i].first -= 10;
				dp[p][i].second++;
			}
		}
	}
	
	cin >> q;	//query
	while (q--) {
		cin >> l >> r;
		--l, --r;
		int p = log_f(r - l + 1);
		cout << dp[p][l].second << '\n';
		cerr << "*************\n";
	}
	return 0;
}