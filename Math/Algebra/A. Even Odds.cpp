#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	ll n, k;
	scanf("%lld %lld", &n, &k);
	ll odd = ceil(n / 2.0);
	if (k <= odd)printf("%lld\n", 1 + --k * 2);
	else printf("%lld\n", (k - odd) * 2);
	return 0;
}