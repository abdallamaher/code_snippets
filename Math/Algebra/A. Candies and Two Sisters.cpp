#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	int t, n, x;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		if (n & 1) x = n / 2;
		else x = --n / 2;
		printf("%d\n", x);
	}
	return 0;
}