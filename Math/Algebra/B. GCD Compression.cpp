#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	int t; scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		vector<int> odd, even;
		for (int i = 1; i <= 2 * n; i++) {
			int x; scanf("%d", &x);
			if (x & 1) odd.push_back(i);
			else even.push_back(i);
		}
		--n;
		for (int i = 1; i < odd.size() && n--; i += 2) {
			printf("%d %d\n", odd[i - 1], odd[i]);
		}
		for (int i = 1; i < even.size() && n--; i += 2) {
			printf("%d %d\n", even[i - 1], even[i]);
		}
	}
	return 0;
}