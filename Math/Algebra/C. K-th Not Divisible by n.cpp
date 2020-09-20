#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	int t, n, d; scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &d, &n);
        /*
            3 give 2
            x give 4
        */
		ll ans = 1ll * n * d / (d - 1);
		if (ans % d == 0)ans--;
		printf("%lld\n", ans);
	}
	return 0;
}