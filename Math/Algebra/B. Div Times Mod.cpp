#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	int n, k;
	scanf("%d %d", &n, &k);
	int x = 1e9;
	for (int i = 1; i < k; i++) {
		if (n%i == 0) {
			int divisor = n / i;
			x = min(x, divisor * k + i);
		}
	}
	printf("%d\n", x);
	return 0;
}