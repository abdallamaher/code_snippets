#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, k;

ll ok(ll x) {
	ll cnt = 0;
	for (int i = 1; i <= n; i++) {
		cnt += min(x / i, m);
	}
	return cnt;
}

int main() {
#ifdef LOCAL   
freopen("input.txt", "r", stdin);
#endif

	scanf("%lld %lld %lld", &n, &m, &k);
	ll st = 0, en = n * m, mid;
	while (st < en) {
		mid = (st + en) >> 1;
		if (ok(mid) >= k)
			en = mid;
		else
			st = mid + 1;
	}
	printf("%lld\n", st);
	return 0;
}
