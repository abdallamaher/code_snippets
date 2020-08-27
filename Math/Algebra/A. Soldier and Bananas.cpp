
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	int k, has, n, pr;
	scanf("%d %d %d", &k, &has, &n);
	pr = k * (n * (n + 1) / 2) - has;
	pr <= 0 ? puts("0") : printf("%d\n", pr);
	return 0;
}