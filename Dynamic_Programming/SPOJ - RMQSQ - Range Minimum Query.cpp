#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
int dp[20][N];
int ar[N];
int n, q, l, r;

int log_f(ll x) {
	int c = 0;
	while (x)x >>= 1, ++c;
	return c - 1;
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n; 
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		dp[0][i] = ar[i];	// building table
	}

	for (int p = 1; p <= log_f(n); p++) {
		int len = (1 << (p - 1));
		for (int i = 0; (i + len) < n; i++) {
			dp[p][i] = min(dp[p - 1][i], dp[p - 1][i + len]);
		}
	}

	cin >> q;		// queres
	while (q--) {
		cin >> l >> r;
		int p = log_f(r - l + 1);
		int len = 1 << p;
		cout << min(dp[p][l], dp[p][r - len + 1]) << '\n';
		cerr << "******\n";
	}
	return 0;
}