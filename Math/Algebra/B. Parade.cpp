#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif

	int n; scanf("%d", &n);
	vector<pair<int, int>> v(n+5, { 0, 0 });
	int suml = 0, sumr = 0;
	for (int i = 1; i <= n; i++) {
		auto& it = v[i];
		scanf("%d %d", &it.first, &it.second);
		suml += it.first;
		sumr += it.second;
	}
	int sum = abs(suml - sumr);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		auto& it = v[i];
		int templ = suml, tempr = sumr;
		templ = templ - it.first + it.second;
		tempr = tempr - it.second + it.first;
		if (abs(templ - tempr) > sum) {
			sum = abs(templ - tempr);
			ans = i;
		}
	}
	printf("%d\n", ans);
	return 0;
}
