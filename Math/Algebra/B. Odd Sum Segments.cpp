#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	int t; scanf("%d", &t);
	while (t--) {
		int n, k; scanf("%d%d", &n, &k);
		vector<int> v(n), ans;
		for(int i=0; i<n; i++) {
			int x; scanf("%d", &x);
			x %= 2;
			if(x) ans.push_back(i);
		}
		int f = ans.size() - k;
		if (f < 0 || (f+1) % 2 == 0) {
			puts("NO");
			continue;
		}
		puts("YES");
		for(int i=0; i < k-1; i++) {
			printf("%d ", ans[i] + 1);
		}
		printf("%d\n", n);
	}
	return 0;
}