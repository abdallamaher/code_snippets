#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	ll a, b; scanf("%lld %lld", &a, &b);
	ll ans = 0;
	while (a > 0 && b > 0) {
		if (b > a)swap(a, b);
		ans += a / b;
		a = a % b;
	}
	printf("%lld\n", ans);
	return 0;
}
