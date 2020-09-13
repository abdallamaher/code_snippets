#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	
	int t; scanf("%d", &t);
	while (t--) {
		int d, v, l, r; scanf("%d %d %d %d", &d, &v, &l, &r);
		printf("%d\n", d / v - r / v + (l - 1) / v);
	}
	return 0;
}