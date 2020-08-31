#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	int n, b, mx = 0, a;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &b);
		a = mx + b;
		mx = max(a, mx);
		printf("%d ", a);
	}
	return 0;
}