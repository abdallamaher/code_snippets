#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, k;
const int N = 3e5 + 5;
int ar[N], sum[N];

bool can(int x) {
	for (int i = 0; i <= n; i++) {
		if (sum[i + x] - sum[i] + k >= x)return 1;
	}
	return 0;
}

int main() {
#ifdef LOCAL   
freopen("input.txt", "r", stdin);
#endif
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", ar + i);
		sum[i] = sum[i - 1] + ar[i];
	}
	int st = 0, en = N, mid;
	while (st < en) {
		mid = (st + en + 1) >> 1;
		if (can(mid))
			st = mid;
		else
			en = mid - 1;
	}
	printf("%d\n", en);
	for (int i = 0; i <= n; i++) {
		if (sum[i + en] - sum[i] + k >= en) {
			for (int j = i+1; j <= i + en; j++) {
				ar[j] = 1;
			}
			break;
		}
	}
	for (int i = 1; i <= n; i++)printf("%d ", ar[i]);
	return 0;
}
