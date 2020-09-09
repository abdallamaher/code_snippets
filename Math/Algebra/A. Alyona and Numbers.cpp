#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	scanf("%d %d", &n, &m);
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += (i + m) / 5 - i / 5;
	}
	printf("%lld\n", sum);
	return 0;
}