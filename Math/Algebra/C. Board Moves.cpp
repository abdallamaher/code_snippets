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
		ll sum = 0, i = 0;
		for (int dis = 0; dis <= n / 2; dis++) {
			sum += dis * i;
			i += 2 * ( 2 + 2 );
		}
		printf("%lld\n", sum);
	}
	return 0;
}