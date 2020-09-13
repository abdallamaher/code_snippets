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
		int ar[105] = {};
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int x;  scanf("%d", &x);
			ar[x]++;
		}
		int ans = 0;
		for (int i = 0; i < 101; i++) {
			if (ar[i] == 0) { ans += i; break; }
			else ar[i]--;
		}
		for (int i = 0; i < 101; i++) {
			if (ar[i] == 0) { ans += i; break; }
			else ar[i]--;
		}
		printf("%d\n", ans);
	}

	return 0;
}
