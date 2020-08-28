#include <bits/stdc++.h>
using namespace std;
#define ll long long


int solve() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		if (n / 2 & 1) { puts("NO"); continue; }
		puts("YES");
		vector<int> v;
		for (int i = 0, j = 2; i < n / 2; i++) {
			v.push_back(j);
			if (i & 1)j += 4;
			else j += 2;
		}
		for (int i = 0; i < n / 2; i++) {
			v.push_back(i & 1 ? v[i] + 1 : v[i] - 1);
		}
		for (auto it : v)
			printf("%d ", it);
		puts("");
	}
	return 0;
}



int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		n /= 2;
		if (n & 1) { puts("NO"); continue; }
		puts("YES");
		for (int i = 1; i <= n; i++) {
			printf("%d ", i * 2);
		}
		for (int i = 1; i < n; i++) {
			printf("%d ", i * 2 - 1);
		}
		printf("%d\n", n * 2 + n - 1);
	}
	return 0;
}