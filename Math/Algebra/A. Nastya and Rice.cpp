#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	int n, a, b, c, d, t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);
		int mn = n * (a - b), mx = n * (a + b);
		int y = c + d, x = c - d;
		if (mn > y || mx < x)puts("No");
		else puts("Yes");
	}
	return 0;
}