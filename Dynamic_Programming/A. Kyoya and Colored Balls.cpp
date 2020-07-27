#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7, N = 1e3 + 7;
ll n, k;
int ar[N];
ll C[N][N];

void ncr() {
	C[0][0] = 1;
	for (int r = 1; r < N; ++r) {
		for (int c = 0; c <= r; ++c) {

			C[r][c] = C[r - 1][c] + C[r - 1][c - 1];

			C[r][c] %= mod;
		}
	}
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> ar[i];
		n += ar[i];
	}

	ncr();

	ll ans = 1;
	for (int i = k-1; i>=0; i--) {
		n--, ar[i]--;	//  last ball of color i before last ball of color i + 1

		ans = (ans * C[n][ar[i]]) % mod;

		n -= ar[i];
	}

	cout << ans;
	return 0;
}