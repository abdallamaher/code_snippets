#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	int n; scanf("%d", &n);
	n -= 2;
	printf("%lld\n", 1ll * n * n);
	return 0;
}