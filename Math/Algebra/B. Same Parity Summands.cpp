#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	int t, n, k; scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		int f = 0;
		int sum = (k-1) * 2;
		if (n - sum > 0 && (n - sum & 1 ^ 1)) {
			puts("YES");
			for (int i = 1; i < k; i++) printf("2 ");
			printf("%d\n", n-sum);
			continue;
		}
		sum = k - 1;
		if ((n - sum > 0 && (n - sum & 1))) {
			puts("YES");
			for (int i = 1; i < k; i++) printf("1 ");
			printf("%d\n", n - sum);
			continue;
		}
		puts("NO");
		
	}
	return 0;
}