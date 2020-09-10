#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif

	int a, b, c; scanf("%d %d %d", &a, &b, &c);
	int x = sqrt(1.0 * a * b / c);
	int y = a / x;
	int z = b / x;
	printf("%lld", 4* (1ll * x + y + z));
	return 0;
}