#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	ll sum = 0;
	for (int i = 0, p = -1, st = 0; i < n; i++) {
		int x; scanf("%d", &x);
		if (!i)sum = x, p = x;
		else {
			if( x <= p) {
				st += p - x;
				p = x;
			}
			else {
				st -= x - p;
				if (st < 0) { sum += -st; st = 0; }
				p = x;
			}
		}
	}
	printf("%lld\n", sum);
	return 0;
}