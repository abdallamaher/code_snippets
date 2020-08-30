#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	int t, n;
	scanf("%d", &t);
	while (t--) {
		int k, n, m;
		scanf("%d %d %d", &k, &n, &m);
		while (n && k > k / 2 + 10) --n, k = k / 2 + 10;
		if (k > m * 10)puts("no");
		else puts("yes");
	}
	return 0;
}