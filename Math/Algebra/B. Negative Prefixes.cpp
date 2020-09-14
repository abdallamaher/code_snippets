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
		vector<int> v(n + 5,0);
		for (int i = 0; i < n; i++) {
			scanf("%d", &v[i]);
		}
		vector<int> chk(n + 5, 0);
		vector<int> unl;
		for (int i = 0; i < n; i++) {
			scanf("%d", &chk[i]);
			if (chk[i] == 0)unl.push_back(v[i]);
		}
		sort(unl.rbegin(), unl.rend());
		int j = 0;
		for (int i = 0; i < n; i++) {
			if (chk[i] == 0) {
				printf("%d ", unl[j]);
				j++;
			}
			else printf("%d ", v[i]);
		}
		puts("");
	}

	return 0;
}