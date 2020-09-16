#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	int x, y; scanf("%d %d", &x, &y);
	ld xx = log((ld)x) / x, yy = log((ld)y) / y;
	if (xx > yy)puts(">");
	else if (xx < yy)puts("<");
	else puts("=");
	return 0;
}