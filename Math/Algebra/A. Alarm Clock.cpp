#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	int t, a, b, c, d;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		if (a  <= b) { printf("%d\n", b); continue; }
		if (a > b && c <= d) { puts("-1"); continue; }
		a -= b;
		int dif = c - d;
		int x =  ( a + dif - 1 ) / dif;		// ceil( a/dif )
		printf("%lld\n", 1ll * x * c + b);
	}

	return 0;
}