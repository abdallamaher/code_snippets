#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	ll sum = n * (n + 1) / 2;
	for (int i = 2; i <= n; i++) {
		if (gcd(sum - i, i) > 1) {
			printf("Yes\n1 %d\n%d ", i, n-1);
			for (int j = 1; j <= n; j++) {
				if (j == i)continue;
				printf("%d ", j);
			}
			return 0;
		}
	}
	puts("No");
	return 0;
}