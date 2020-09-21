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
		ll n, k; scanf("%lld%lld", &n, &k);
		for(int i=1; i<k; i++) {
			ll mn = 19, mx = 0;
			ll tmp = n;
			while (tmp) {
				mn = min(mn, tmp % 10);
				mx = max(mx, tmp % 10);
				tmp /= 10;
			}
			n += mn * mx;
			if (mn == 0)break;
		}
		printf("%lld\n", n);
	}


	return 0;
}