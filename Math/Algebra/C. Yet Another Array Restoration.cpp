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
		int n, a, b; scanf("%d%d%d", &n, &a, &b);
		int def = 0, en = 1e9;
		for (int i = n; i > 0; i--) {
			for (int j = 1; j <= n && i > j; j++) {
				if ((b - a) % (i - j) == 0) {
					int diff = (b - a) / (i - j);
					int st = a - (j - 1) * diff;
					if (st <= 0)continue;
					int last = st + diff * (n - 1);
					if (last < en) {
						en = last;
						def = diff;
					}
				}
			}
		}
		for (int i = 0; i < n; i++)printf("%d ", en - i * def);
		puts("");
	}

	return 0;
}