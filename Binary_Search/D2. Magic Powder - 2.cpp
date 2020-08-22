#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, r;
const int N = 1e5 + 5;
ll need[N], have[N];

bool can(ll x) {
	ll rr = r;
	for (int i = 0; i < n; i++) {
		ll rem = (x * need[i]) - have[i];
		if (rem > r)return 0;
		if (rem > 0)rr -= rem;
	}
	return rr >= 0;
}

int main() {
#ifdef LOCAL   
freopen("input.txt", "r", stdin);
#endif

	scanf("%d %d", &n, &r);
	for (int i = 0; i < n; i++)scanf("%d", need + i);
	for (int i = 0; i < n; i++)scanf("%d", have + i);

	ll st = 0, en = 2e9 + 5, mid;
	while (st < en) {
		mid = (st + en + 1) >> 1;
		if (can(mid)) 
			st = mid;
		else 
			en = mid - 1;
	}
	printf("%lld\n", en);
	return 0;
}
