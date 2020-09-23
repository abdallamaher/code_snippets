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
		int n; scanf("%d", &n);
		vector<int> v(n);
		for (auto &it : v)scanf("%d", &it);
		int f = 1;
		for (int i = 1; i < n; i++) {
			if (abs(v[i] - v[i - 1])>=2) {
				printf("YES\n%d %d\n", i, i + 1);
				f = 0;
				break;
			}
		}
		if(f)puts("NO");
	}
	return 0;
}