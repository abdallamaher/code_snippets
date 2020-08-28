#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	ll n; scanf("%lld", &n);
	if (n & 1)printf("%lld\n", (-1 * n) + (n / 2));
	else printf("%lld\n", n - (n / 2));

	return 0;
}