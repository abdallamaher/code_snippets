#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	int t, x, y, a, b;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d %d", &x, &y, &a, &b);
		if (x > y)swap(x, y);
		ll sum = 0;
		if (2 * a > b) { sum += 1ll * x * b; y -= x; x = 0; }
		sum += 1ll * x * a + 1ll * y * a;
		printf("%lld\n", sum);
	}
	return 0;
}