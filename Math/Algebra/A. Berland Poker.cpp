#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	int n, m, k, t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &n, &m, &k);
		n /= k;
		if (n >= m)printf("%d\n", m);
		else {
			--k;
			printf("%d\n", n - (m - n + k - 1) / k);
		}
	}
	return 0;
}