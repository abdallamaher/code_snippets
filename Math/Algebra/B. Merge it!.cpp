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
		int ar[4] = {};
		for (int i = 0; i < n; i++) {
			int x;  scanf("%d", &x);
			ar[x % 3]++;
		}
		int mn = min(ar[1], ar[2]);
		ar[1] -= mn; 
		ar[2] -= mn;
		ll ans = mn + ar[2] / 3 + ar[1] / 3;
		printf("%lld\n", ans + ar[0]);
	}
	return 0;
}
