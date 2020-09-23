#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	int n; scanf("%d", &n);
	vector<int> v, mark(105);
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		if (!mark[x]) {
			v.push_back(x);
			mark[x] = 1;
		}
	}

	int ans = -1;
	sort(v.begin(), v.end());
	if (v.size() == 1) ans = 0; 
	else if (v.size() == 2) {
		ans = v[1] - v[0];
		if (ans % 2 ==0)ans /= 2;
	}
	else if (v.size() == 3) {
		if (v[1] - v[0] == v[2] - v[1])
			ans = v[1] - v[0];
	}
	printf("%d\n", ans);
	return 0;
}