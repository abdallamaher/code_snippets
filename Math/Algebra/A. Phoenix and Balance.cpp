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
		int n; scanf("%d", &n);
		int sum1 = 0, sum2 = 0;
		for (int i = 1; i < n / 2; ++i) {
			sum1 += (1 << i);
		}
		sum1 += (1 << n);

		for (int i = n / 2; i < n; ++i) {
			sum2 += (1 << i);
		}
		printf("%d\n", sum1 - sum2);
	}
	return 0;
}