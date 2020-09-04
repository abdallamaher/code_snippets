#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	scanf("%d %d", &n, &m);
	if (m > n)swap(n, m);
	int ans = 0;
	while (n >= 2 && m>=1) {
		n -= 2;
		m++;
		ans++;
		if (m > n)swap(n, m);
	}
	printf("%d\n", ans);
	return 0;
}