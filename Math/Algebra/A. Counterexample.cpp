#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	ll r, l; scanf("%lld %lld", &r, &l);
	if (r & 1)r++;
	if (l - r < 2)return puts("-1"), 0;
	printf("%lld %lld %lld", r, r + 1, r + 2);

	return 0;
}