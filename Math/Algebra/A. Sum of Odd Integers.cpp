#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	int n, k, t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &k);
		if (1ll * k * k > n)puts("NO");
		else if (n % 2  != k % 2) puts("NO");
		else puts("YES");
	}
	return 0;
}