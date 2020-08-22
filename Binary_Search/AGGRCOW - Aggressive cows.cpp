#include <bits/stdc++.h>
using namespace std;
#define ll long long
int t, n, c;
const int N = 1e5 + 5;
int ar[N];

bool can(int x) {
	int cnt = 0, p = 0;
	for (int i = 1; i < n; i++) {
		if (ar[i] - ar[p] >= x)p = i, cnt++;
	}
	return cnt >= c-1;
}

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &c);
		for (int i = 0; i < n; i++) {
			scanf("%d", ar + i);
		}
		sort(ar, ar + n);
		int st = 0, en = 1e9, mid;
		while (st < en) {
			mid = (st + en + 1) >> 1;
			if (can(mid))
				st = mid;
			else
				en = mid - 1;
		}
		printf("%d\n", en);
	}
	return 0;
}
