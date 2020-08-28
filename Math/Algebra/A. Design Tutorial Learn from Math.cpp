#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	if (n & 1)printf("%d %d\n", 9, n - 9);
	else printf("%d %d\n", 4, n - 4);
	return 0;
}