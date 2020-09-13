#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	int t, n;
	scanf("%d", &t);
	while (t--) {
		const int N = 1e5 + 5;
		int ar[N] = {};
		scanf("%d", &n);
		for (int i = 0; i < n; i++)scanf("%d", ar + i);
		sort(ar, ar + n);
		int i = 0, l = n - 1;
		ll ans = 1ll * ar[l] * ar[l - 1] * ar[l - 2] * ar[l - 3] * ar[l - 4];		// take 0 neg or all small neg
		ans = max(ans, 1ll * ar[i] * ar[i + 1] * ar[i + 2] * ar[i + 3] * ar[l]);	// take 2 neg
		ans = max(ans, 1ll * ar[i + 1] * ar[l] * ar[l - 1] * ar[l - 2] * ar[i]);	// take 4 neg

		printf("%lld\n", ans);
	}
	return 0;
}
