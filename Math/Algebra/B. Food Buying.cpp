#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		ll sum = 0;
		while (n) {
			if (n >= 10) {
				ll m = n / 10;
				sum += m * 10;
				n = n % 10 + m;
			}
			else {
				sum += n;
				n = 0;
			}
		}
		printf("%lld\n", sum);
	}

	return 0;
}