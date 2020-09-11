#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	while (t--) {
		ll a, b;
		scanf("%lld %lld", &a, &b);
		ll x = 0, num = 9;
		while (num <= b) x++, num = num * 10 + 9;
		printf("%lld\n", x * a);
	}
	return 0;
}
