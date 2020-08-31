#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	int t, n, k;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &k);
		// divisor
		int d = n;
		for (int i = 2; i * i <= n; i++) {
			if (n%i == 0) {
				d = min(d, i);
				d = min(d, n / i);
			}
		}

		// proof : if n odd [ it's first divisor odd ] 
		// odd + odd = even
		// first divisor for any even is 2
		n += d;
		printf("%lld\n", 1ll * --k * 2 + n);
	}
	return 0;
}