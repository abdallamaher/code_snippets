#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int OO = 1e9 + 9;
#define ll long long 

int n, l, r, q1, q2;
int ar[N], sumR[N], sumL[N];

int main() {
	cin.sync_with_stdio(false);
	cin >> n >> l >> r >> q1 >> q2;
	for (int i = 1; i <= n; ++i) {
		cin >> ar[i];
	}
	for (int i = 1; i <= n; i++) {
		sumR[i] = sumR[i - 1] + ar[i] * r;
		sumL[i] = sumL[i - 1] + ar[i] * l;
	}
	int ans = OO;
	for (int i = 0; i <= n; ++i) {
		if (!i) {
			ans = min(ans, sumR[n] + (n-1) * q2);
			continue;
		}
		int s = n - i;
		int f = i;
		if (s > f) {
			s -= f + 1;
			f = 0;
		}
		else if (s == f) {
			f = 0;
			s = 0;
		}
		else {
			f -= s + 1;
			s = 0;
		}
		ans = min(ans, sumL[i] + f * q1 + sumR[n] - sumR[i] + s * q2);
	}
	cout << ans;
	return 0;
}









