#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	int t; scanf("%d", &t);
	while (t--) {
		int n, a, b, f; scanf("%d", &n);
		a = 0, b = 0, f = 1;
		while (n--) {
			int x, y; scanf("%d%d", &x, &y);
			if (x < y || x < a || y < b || (y-b+a > x))f = 0;
			a = x, b = y;
		}
		puts(f ? "YES" : "NO");
	}
	return 0;
}