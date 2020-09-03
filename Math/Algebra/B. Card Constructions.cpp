#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	ll t, n;
	scanf("%lld", &t);
	vector<ll> v;
	for (int i = 1; i < N; i++) {
		v.push_back(2ll * (i)*(i + 1) / 2 + (i - 1) * i / 2);
	}
	while (t--) {
		scanf("%lld", &n);
		int lev = lower_bound(v.begin(), v.end(), n) - v.begin();
		int sum = 0;
		for (int i = lev; i >= 0; i--) {
			int z = n / v[i];
			n -= z * v[i];
			sum += z;
		}

		printf("%d\n", sum);
	}

	return 0;
}