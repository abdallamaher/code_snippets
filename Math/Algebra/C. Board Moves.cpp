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
		ll n; scanf("%lld", &n);
		ll sum = 0, dis = 1, i = 4;
		n = n * n;
		while(n > 1) {
			sum += dis * 2 * i;
			n -= 2 * i;
			i += 4;
			dis++;
		}
		printf("%lld\n", sum);
	}
	return 0;
}