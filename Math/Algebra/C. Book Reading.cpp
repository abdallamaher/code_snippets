#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	int t; scanf("%d", &t);
	while (t--) {
		ll n, m; scanf("%lld%lld", &n, &m);
		int ar[12] = {};
		for (int i = 1; i <= 10; i++) {
			ar[i] = (m * i) % 10;
			ar[i] += ar[i - 1];
		}
		ll diff = n / m;
		printf("%lld\n", ar[10] * (diff / 10) + ar[diff % 10]);
		cerr << "************\n";
	}
	return 0;
}