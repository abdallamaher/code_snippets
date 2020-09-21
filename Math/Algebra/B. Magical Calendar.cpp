#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	
	int t; scanf("%d", &t);
	while (t--) {
		int n, r; scanf("%d%d", &n, &r);
		ll sum = 0;
		if (r >= n) {
			r = n - 1;
			sum++;
		}
		sum += 1ll * r * (r + 1) / 2;
		printf("%lld\n", sum);
	}
	return 0;
}