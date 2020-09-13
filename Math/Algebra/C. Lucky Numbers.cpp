#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	ll n;
	scanf("%lld", &n);
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += (1ll << i);
	}
	printf("%lld\n", ans);
	return 0;
}