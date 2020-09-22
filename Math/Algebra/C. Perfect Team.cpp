#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	int t, c, m, x; scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &c, &m, &x);
		int ans = min((c + m + x) / 3, min(c, m));
		printf("%d\n", ans);
	}
	return 0;
}