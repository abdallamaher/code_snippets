#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	int n, m, a;
	scanf("%d %d %d", &n, &m, &a);
	if (n < m)swap(n, m);
	ll ans = 0;
	ans += (n + a - 1) / a;
	ans *= (m + a - 1) / a;
	printf("%lld",  ans);
	return 0;
}