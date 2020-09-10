#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int ar[100] = {};
		int i = 1;
		for (; i <= n; i++) {
			scanf("%d", ar + i);
		}
		i = 1;
		cerr << n << endl;
		for (; i <= n / 2; i++) {
			if (i & 1 && ar[i] > 0) ar[i] *= -1;
			else if(i&1^1 &&  ar[i] < 0)ar[i] *= -1;
		}
		i = n;
		for (; i > n/2; i--) {
			if (i & 1 && ar[i] > 0) ar[i] *= -1;
			else if (i & 1 ^ 1 && ar[i] < 0)ar[i] *= -1;
		}
		for (int i = 1; i <= n; i++)printf("%d ", ar[i]);
		puts("");
	}

	return 0;
}