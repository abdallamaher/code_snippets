#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	ll l, r, a, b, k; 
	scanf("%lld %lld %lld %lld %lld", &l, &r, &a, &b, &k);
	ll x = max(l, a);
	ll y = min(r, b);
	ll ans = max(0ll, y - x + 1);
	if (ans && x <= k && k <= y)ans--;
	printf("%lld", ans);
	return 0;
}