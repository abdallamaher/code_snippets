#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	int x = 8 * 9 * 5 * 7;
	ll n; scanf("%lld", &n);
	printf("%lld\n", n / x);

	return 0;
}